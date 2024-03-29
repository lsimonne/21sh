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
#include "utils.h"

void	print_token(t_token const *token)
{
	ft_printf("%s: s=", token->type->name);
	ft_printf("%s\n", token->str);
	ft_putchar('\n');
}

void	print_tokens(t_token const *tokens)
{
	if (tokens == NULL)
		return ;
	print_token(tokens);
	print_tokens(tokens->next);
}
