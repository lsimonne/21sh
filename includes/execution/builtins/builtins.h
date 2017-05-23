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

#ifndef BUILTINS_H
# define BUILTINS_H

# include "variable.h"
# include "../../parse_input/syntax_tree.h"

# define STATUS_SUCCESS 0
# define STATUS_FAILURE -1
# define BUILTIN_RET int
# define BUILTIN_ARGS argc, char **argv int argc, char **argv

typedef int	(*t_builtin)(int argc, char **argv);

int	builtin_cd(int argc, char **argv);
int	builtin_setenv(int argc, char **argv);
int	builtin_unsetenv(int argc, char **argv);
int	builtin_set(int argc, char **argv);
int	builtin_export(int argc, char **argv);
int	builtin_unset(int argc, char **argv);
int	builtin_exit(int argc, char **argv);
int	builtin_history(int argc, char **argv);

/*
**	SUB BUILTIN
*/

/*
** setenv, unsetenv
*/
int			setenv_as(t_variable **env, char *name, char *value, bool exported);
int			unsetenv_as(t_variable **env, char *name);
/*
** echo
*/

int			builtin_echo(int argc, char **argv);
void		display_echo(int argc, char **argv, char *opt, int i);
bool		escape_char(char *str);
bool		escape(int c);
int			octal(char *c);

/*
** env.c
*/
int			builtin_env(int argc, char **argv, t_simple_command *cmd);
void		run_env(int argc, char **argv, t_simple_command *cmd);

#endif
