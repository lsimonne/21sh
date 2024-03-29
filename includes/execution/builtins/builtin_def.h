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

#ifndef BUILTIN_DEF_H
# define BUILTIN_DEF_H

# include <stdbool.h>
# include "builtins.h"

typedef enum				e_builtin_id
{
	CD_BUID = 0,
	ECHO_BUID,
	EXIT_BUID,
	SETENV_BUID,
	UNSETENV_BUID,
	SET_BUID,
	UNSET_BUID,
	EXPORT_BUID,
	HISTORY_BUID,
	ENV_BUID
}							t_builtin_id;

typedef struct				s_builtin_def
{
	t_builtin_id const			id;
	char const *const			name;
	t_builtin const				builtin;
}							t_builtin_def;

# define BUILTIN_DEF_COUNT 9

t_builtin_def const			*get_builtin_defs(void);
t_builtin_def const			*get_matching_builtin(char const *str);

void						print_builtin_def(t_builtin_def const *def);
void						print_builtin_defs(void);

#endif
