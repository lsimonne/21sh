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
#include <libft.h>
#include "utils.h"

static bool	lex_operator(t_token *token)
{
	t_token_def const	*match;

	match = get_operator(token->str);
	if (match != NULL)
	{
		token->type = match;
		return (true);
	}
	return (false);
}

static bool	is_io_number(char c)
{
	if (c == '<' || c == '>')
		return (true);
	return (false);
}

static bool	lex_io_number(t_token *token, char delim)
{
	if (str_is_digits(token->str) && is_io_number(delim))
	{
		token->type = get_token_def(IO_NUMBER_TOKID);
		return (true);
	}
	return (false);
}

void		lex_me(t_token *token, char delim)
{
	if (!lex_operator(token))
		lex_io_number(token, delim);
}
