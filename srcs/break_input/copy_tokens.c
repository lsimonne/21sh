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

#include "utils.h"
#include "token.h"
#include <libft.h>
#include "break_input/lexer.h"
#include "abstract_list.h"

t_token		*copy_token(t_token const *src)
{
	t_token	*dst;

	dst = memalloc_or_die(sizeof(t_token));
	dst->str = ft_strdup(src->str);
	dst->type = src->type;
	return (dst);
}

t_token		*tokens_dup_until(t_token const *tokens, t_token const *stop)
{
	t_token	*result;
	t_token	**it;

	result = NULL;
	it = &result;
	while (tokens != NULL && tokens != stop)
	{
		*it = copy_token(tokens);
		it = &(*it)->next;
		tokens = tokens->next;
	}
	*it = NULL;
	return (result);
}

t_token		*copy_all_tokens(t_token const *src)
{
	return (tokens_dup_until(src, NULL));
}
