/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memalloc_or_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:31:14 by lsimonne          #+#    #+#             */
/*   Updated: 2017/05/16 17:31:57 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*memalloc_or_die(size_t size)
{
	void *m;

	m = malloc(size);
	if (!m)
	{
		ft_printf("Oh no! malloc is too heavy for me\n");
		exit(-1);
	}
	ft_bzero(m, size);
	return (m);
}
