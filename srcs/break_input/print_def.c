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

#include "token_def.h"
#include "uint.h"
#include <libft.h>

static void					print_token_str(char const *str)
{
	char c;

	ft_putstr(": ");
	if (str == NULL)
	{
		ft_putstr("not an operator");
		return ;
	}
	ft_putchar('"');
	while ((c = *str) != '\0')
	{
		if (c == '\n')
			ft_putstr("\\n");
		else
			ft_putchar(c);
		str += 1;
	}
	ft_putchar('"');
}

void						print_token_def(t_token_def const *def)
{
	ft_printf("%s", def->name);
	print_token_str(def->str);
}

void						print_token_defs(void)
{
	t_token_def const	*defs;
	t_uint				u;

	ft_putstr("TOKEN DEFS:\n");
	defs = get_token_defs();
	u = 0;
	while (u < TOKEN_DEF_COUNT)
	{
		print_token_def(defs + u);
		ft_putchar('\n');
		u += 1;
	}
}
