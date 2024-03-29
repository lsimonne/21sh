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

#include "token.h"

static bool				get_last_nl_list_start_impl(t_token const *tokens
	, t_token const **result_addr)
{
	if (tokens == NULL)
	{
		*result_addr = NULL;
		return (true);
	}
	else if (get_last_nl_list_start_impl(tokens->next, result_addr)
		&& tokens->type->id == NEWLINE_TOKID)
	{
		*result_addr = tokens;
		return (true);
	}
	else
		return (false);
}

static t_token const	*get_last_nl_list_start(t_token const *tokens)
{
	t_token const *result;

	get_last_nl_list_start_impl(tokens, &result);
	return (result);
}

t_token					*trim_newlines(t_token const *tokens)
{
	while (tokens != NULL && tokens->type->id == NEWLINE_TOKID)
		tokens = tokens->next;
	return (tokens_dup_until(tokens, get_last_nl_list_start(tokens)));
}
