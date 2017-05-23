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

#ifndef CD_H
# define CD_H

#include "strlist.h"

typedef struct 	s_cd {

	char	*directory;
	char	*curpath;
	char	*new_pwd;
	char	*current_pwd;
	t_uchar	opt;
}				t_cd;

char		*canonicalize_path(char const *path);
bool		comp_is_dot(char const *comp);
bool		comp_is_dot_dot(char const *comp);
void		remove_dots(t_strlist **cmpnts_addr);
bool		last_is_slash(char const *str);
bool		first_comp_is_dot_or_dotdot(char const *str);
int			cd_oldpwd();
void		set_curpath_from_pwd(char **str_addr);
char		*test_cdpath(char const *dir, char const *path);
char		*find_cdpath(char const *directory);
char		*parse_cd_options(t_uchar *opt_addr, int argc, char **argv);
bool		set_home_as_dir(t_cd *cd);
void		set_pwds(t_cd cd);

#endif
