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
#include <stdlib.h>

void	delete_token(t_token **token_addr)
{
	t_token *token;

	token = *token_addr;
	if (token != NULL)
	{
		free(token->str);
		free(token);
		*token_addr = NULL;
	}
}

void	delete_all_tokens(t_token **tokens_addr)
{
	t_token *token;

	token = *tokens_addr;
	if (token != NULL)
		delete_all_tokens(&token->next);
	delete_token(tokens_addr);
}
