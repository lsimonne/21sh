/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:01:15 by lsimonne          #+#    #+#             */
/*   Updated: 2017/05/23 22:01:17 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/builtins/builtins.h"
#include "variable.h"
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "uint.h"
#include "errors.h"
#include <errno.h>
#include "utils.h"
#include "execution/builtins/cd.h"
#include <limits.h>

bool			last_is_slash(char const *str)
{
	if (str == NULL)
		return (false);
	return (str[ft_strlen(str) - 1] == '/');
}

bool			first_comp_is_dot_or_dotdot(char const *str)
{
	if ((str[0] == '.' && (str[1] == '/' || str[1] == '\0'))
			|| (str[0] == '.' && str[1] == '.' \
				&& (str[2] == '/' || str[2] == '\0')))
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

int				cd_oldpwd(t_cd *cd)
{
	int		ret;
	char	*oldpwd;

	free(cd->directory);
	free(cd->current_pwd);
	oldpwd = get_variable("OLDPWD");
	if (oldpwd == NULL)
	{
		ft_putendl_fd("42sh: cd -: OLDPWD not set", 2);
		return (EXIT_FAILURE);
	}
	ret = builtin_cd(2, (char*[]){"cd", oldpwd, NULL});
	if (ret == EXIT_SUCCESS)
		ft_putendl(get_variable("PWD"));
	free(oldpwd);
	return (ret);
}

void			set_curpath_from_pwd(char **str_addr)
{
	char	*path;

	if (str_addr == NULL || *str_addr == NULL)
		fatal_error("NULL ptr fed to set_curpath_from_pwd");
	if ((*str_addr)[0] == '/')
		return ;
	path = get_variable("PWD");
	if (!last_is_slash(path))
		path = ft_strjoinf(path, "/", 1);
	*str_addr = ft_strjoinf(path, *str_addr, 3);
}
