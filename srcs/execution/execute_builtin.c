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

#include "execute_syntax_tree.h"
#include "utils.h"
#include <libft.h>
#include "variable.h"
#include <stdio.h>
#include "execute_builtin.h"

bool			check_if_env(t_simple_command *cmd, \
				t_variable **env_backup, t_error_id *ret)
{
	if (ft_strcmp(cmd->argv[0], "env") == 0)
	{
		set_env_exec(env_backup, cmd->assignments);
		*ret = builtin_env(ft_tablen(cmd->argv), cmd->argv, cmd);
		return (true);
	}
	return (false);
}

static bool		execute_other_builtin(t_simple_command *cmd, \
				t_variable **env_backup, t_error_id *ret)
{
	t_builtin_def const		*builtin;

	builtin = get_matching_builtin(cmd->argv[0]);
	if (builtin == NULL)
		return (1);
	set_env_exec(env_backup, cmd->assignments);
	if (builtin->builtin == NULL)
		return (1);
	*ret = builtin->builtin(ft_tablen(cmd->argv), cmd->argv);
	set_variable("_", cmd->argv[ft_tablen(cmd->argv) - 1], false);
	return (0);
}

t_error_id		execute_builtin(t_simple_command *cmd, size_t lvl)
{
	t_error_id				ret;
	t_variable				*env_backup;

	(void)lvl;
	if (cmd->argv[0] == NULL)
		fatal_error("NULL argv[0] fed to execute_builtin");
	ret = NO_ERROR;
	if (cmd != NULL)
	{
		set_variable("_", cmd->argv[0], false);
		if (check_if_env(cmd, &env_backup, &ret))
			;
		else
		{
			if (execute_other_builtin(cmd, &env_backup, &ret))
				return (NO_SUCH_BUILTIN);
		}
		reset_env(cmd, env_backup);
	}
	if (get_error() != ENV_EXEC_ERR)
		set_last_exit_status(ret);
	if (ret != 0)
		ret = CHILD_FAILURE;
	return (ret);
}
