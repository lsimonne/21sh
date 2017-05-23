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

#include "parse_input/syntax_tree.h"
#include "errors.h"
#include "utils.h"
#include <libft.h>
#include "execute_syntax_tree.h"

#include <stdio.h>

t_error_id	execute_and_or_list(t_and_or_list *ao_list, size_t lvl)
{
	t_error_id		ret;
	bool			skip;

	if (ao_list == NULL)
		return (NO_ERROR);
	if (ao_list->next == NULL)
		return (execute_pipeline(ao_list->pipeline, lvl));
	skip = false;
	while (ao_list != NULL)
	{
		if (!skip)
			ret = execute_pipeline(ao_list->pipeline, lvl + 1);
		skip = false;
		if ((ret == NO_ERROR && ao_list->separation_type == AO_OR)
			|| (ret != NO_ERROR && ao_list->separation_type == AO_AND))
		{
			skip = true;
		}
		ao_list = ao_list->next;
	}
	return (ret);
}

t_error_id	execute_command_list(t_command_list *cmd_list)
{
	t_error_id		ret;

	if (cmd_list == NULL)
		return (NO_ERROR);
	if (cmd_list->next == NULL)
		return (execute_and_or_list(cmd_list->and_or_list, 0));
	while (cmd_list != NULL)
	{
		ret = execute_and_or_list(cmd_list->and_or_list, 1);
		cmd_list = cmd_list->next;
	}
	return (ret);
}
