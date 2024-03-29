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

#include "history.h"
#include "history/substitution/history_substitutions.h"
#include "errors.h"
#include "abstract_list.h"
#include "utils.h"

#include "history_debug.h"

static void		get_args(int argc, char **argv, int i, t_hist_opt *options)
{
	options->args = copy_array(argv, i, argc);
	if (get_error() == NO_ERROR && options->d && !options->offset)
	{
		if (options->args && options->args[0])
			options->offset = ft_strdup(options->args[0]);
		else
			error_builtin("history", NULL, NEED_NUM);
	}
}

static void		hist_parse_options(int argc, char **argv, t_hist_opt *options)
{
	int			i;

	i = 1;
	while (i < argc)
	{
		if (get_error() != NO_ERROR)
			return ;
		if (argv[i][0] == '-')
		{
			if (!get_hist_options(argv[i], options))
			{
				i++;
				break ;
			}
		}
		else
			break ;
		i++;
	}
	get_args(argc, argv, i, options);
}

int				builtin_history(int argc, char **argv)
{
	t_hist_opt	options;

	set_error(NO_ERROR);
	ft_bzero(&options, sizeof(options));
	hist_parse_options(argc, argv, &options);
	if (get_error() == NO_ERROR)
		execute_options(&get_shell_env()->history.list, options);
	free_history_options(&options);
	return (get_error());
}
