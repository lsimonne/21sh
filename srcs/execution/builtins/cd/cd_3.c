/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 00:35:20 by lsimonne          #+#    #+#             */
/*   Updated: 2017/05/24 00:35:22 by lsimonne         ###   ########.fr       */
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

char			*test_cdpath(char const *dir, char const *path)
{
	char	*result;

	result = NULL;
	if (!(path == NULL || path[0] == '\0'))
	{
		if (last_is_slash(path))
			result = ft_strdup(path);
		else
			result = ft_strjoin(path, "/");
		result = ft_strjoinf(result, dir, 1);
	}
	else
		result = ft_strjoin("./", dir);
	if (result != NULL && !is_directory(result))
		ft_strdel(&result);
	return (result);
}

char			*find_cdpath(char const *directory)
{
	char	*cdpath;
	char	**slices;
	char	*str;
	size_t	u;

	cdpath = get_variable("CDPATH");
	if (cdpath == NULL)
		cdpath = ft_strdup("");
	slices = ft_strsplit(cdpath, ':');
	u = 0;
	str = NULL;
	while (u == 0 || slices[u] != NULL)
	{
		str = test_cdpath(directory, slices[u]);
		if (str != NULL)
			break ;
		if (u == 0 && slices[u] == NULL)
			break ;
		u++;
	}
	free(cdpath);
	ft_freetabchar(slices);
	return (str);
}

char			*parse_cd_options(t_uchar *opt_addr, int argc, char **argv)
{
	char	*str;

	(void)argc;
	*opt_addr = '\0';
	if (*argv == NULL)
		return (NULL);
	argv++;
	while ((str = *argv) != NULL)
	{
		if (str[0] == '-' && (str[1] == 'L' || str[1] == 'P'))
			*opt_addr = str[1];
		else
			return (ft_strdup(str));
		argv++;
	}
	return (NULL);
}

bool			set_home_as_dir(t_cd *cd)
{
	char *home;

	home = get_variable("HOME");
	if (home == NULL || home[0] == '\0')
	{
		ft_putendl_fd("42sh: cd: HOME not set", 2);
		return (1);
	}
	else
		cd->directory = home;
	return (0);
}

void			set_pwds(t_cd cd)
{
	set_variable("OLDPWD", cd.current_pwd, true);
	set_variable("PWD", cd.new_pwd, true);
}
