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

#include "builtins.h"

#include "history/builtin/history.h"

#include "utils.h"
#include <libft.h>

int		builtin_exit(int argc, char **argv)
{
	int			ret;
	t_shell_env	*shell_env;

	if (argc > 1)
		ret = ft_atoi(argv[1]);
	else
		ret = get_last_exit_status();
	if (ret < 0)
	{
		ft_dprintf(STDERR_FILENO, "%s: wrong exit value: %d\n", SHNAME, ret);
		ret = 2;
	}
	else if (ret > 255)
	{
		ret = ret % 256;
	}
	shell_env = get_shell_env();
	hist_to_file(shell_env->history.list, shell_env->history.histfile, true);
	exit(ret);
}
