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

static char			*parse_options(t_uchar *opt_addr, int argc, char **argv)
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

static char			*test_cdpath(char const *dir, char const *path)
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

static char			*find_cdpath(char const *directory)
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

int					builtin_cd(int argc, char **argv)
{
	char	*directory;
	char	*curpath;
	char	*home;
	char	*new_pwd;
	char	*current_pwd;
	t_uchar	opt;
	int		ret;

	current_pwd = getcwd(NULL, 0);
	curpath = NULL;
	directory = parse_options(&opt, argc, argv);
	if (directory == NULL)
	{
		home = get_variable("HOME");
		if (home == NULL || home[0] == '\0')
		{
			ft_putendl_fd("42sh: cd: HOME not set", 2);
			return (EXIT_FAILURE);
		}
		else
			directory = home;
	}
	if (ft_strequ(directory, "-"))
	{
		free(directory);
		free(current_pwd);
		return (cd_oldpwd());
	}
	if (directory[0] == '/')
		curpath = ft_strdup(directory);
	else
	{
		if (!first_comp_is_dot_or_dotdot(directory))
			curpath = find_cdpath(directory);
		if (curpath == NULL)
			curpath = ft_strdup(directory);
	}
	if (opt != 'P')
	{
		set_curpath_from_pwd(&curpath);
		strfreeswap(&curpath, canonicalize_path(curpath));
		if (curpath == NULL)
		{
			free(directory);
			return (EXIT_SUCCESS);
		}
		new_pwd = ft_strdup(curpath);
		save_the_day(&curpath, directory, current_pwd);
	}
	ret = chdir(curpath);
	if (ret == -1)
		print_errno_error(errno, "cd", curpath);
	else if (opt != 'P')
	{
		set_variable("OLDPWD", current_pwd, true);
		set_variable("PWD", new_pwd, true);
	}
	free(curpath);
	free(directory);
	if (ret != 0)
		ret = 2;
	return (ret);
}
