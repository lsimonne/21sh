/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <lsimonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:35:21 by lsimonne          #+#    #+#             */
/*   Updated: 2017/05/04 15:35:21 by lsimonne         ###   ########.fr       */
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
#include "execution/builtins/cd.h"

void				save_the_day(char **curpath_addr, char const *directory, \
							char const *pwd)
{
	char	*str;

	if (curpath_addr == NULL || *curpath_addr == NULL)
		fatal_error("NULL ptr fed to save_the_day");
	if (!(ft_strlen(*curpath_addr) + 1 > PATH_MAX \
		&& ft_strlen(directory) + 1 <= PATH_MAX))
		return ;
	if (!last_is_slash(pwd))
		str = ft_strjoin(pwd, "/");
	else
		str = ft_strdup(pwd);
	if (!ft_strstr(*curpath_addr, str))
		return ;
	strfreeswap(curpath_addr, ft_strdup((*curpath_addr) + ft_strlen(str)));
	free(str);
}

static bool			execute_cd(t_cd *cd)
{
	if (cd->opt != 'P')
	{
		set_curpath_from_pwd(&cd->curpath);
		strfreeswap(&cd->curpath, canonicalize_path(cd->curpath));
		if (cd->curpath == NULL)
		{
			free(cd->directory);
			return (0);
		}
		cd->new_pwd = ft_strdup(cd->curpath);
		save_the_day(&cd->curpath, cd->directory, cd->current_pwd);
	}
	return (1);
}

static void			set_curpath(t_cd *cd)
{
	if (!first_comp_is_dot_or_dotdot(cd->directory))
		cd->curpath = find_cdpath(cd->directory);
	if (cd->curpath == NULL)
		cd->curpath = ft_strdup(cd->directory);
}

static void			end_cd(t_cd *cd, int *ret)
{
	free(cd->curpath);
	free(cd->directory);
	if (*ret != 0)
		*ret = 2;
}

int					builtin_cd(int argc, char **argv)
{
	t_cd	cd;
	int		ret;

	cd.current_pwd = getcwd(NULL, 0);
	cd.curpath = NULL;
	cd.directory = parse_cd_options(&cd.opt, argc, argv);
	if (cd.directory == NULL)
	{
		if (set_home_as_dir(&cd))
			return (EXIT_SUCCESS);
	}
	if (ft_strequ(cd.directory, "-"))
		return (cd_oldpwd(&cd));
	if (cd.directory[0] == '/')
		cd.curpath = ft_strdup(cd.directory);
	else
		set_curpath(&cd);
	if (!execute_cd(&cd))
		return (EXIT_SUCCESS);
	if ((ret = chdir(cd.curpath)) == -1)
		print_errno_error(errno, "cd", cd.curpath);
	else if (cd.opt != 'P')
		set_pwds(cd);
	end_cd(&cd, &ret);
	return (ret);
}
