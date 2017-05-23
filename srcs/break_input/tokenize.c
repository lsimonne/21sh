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
#include <libft.h>
#include "tokenizer.h"
#include "errors.h"

t_token			*tokenize(char const *input)
{
	t_token						*result;
	t_tokenizer_state			state;

	set_error(NO_ERROR);
	result = NULL;
	if (input != NULL)
	{
		ft_bzero(&state, sizeof(t_tokenizer_state));
		state.input = ft_strdup(input);
		state.current_char = state.input;
		while (*state.current_char != '\0')
		{
			apply_rules(&state);
			if (get_error() != NO_ERROR)
			{
				free(state.input);
				delete_all_tokens(&state.result);
				return (NULL);
			}
		}
		delimit_token(&state);
		result = state.result;
		free(state.input);
	}
	return (result);
}
