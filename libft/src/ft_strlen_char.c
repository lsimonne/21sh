/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <lsimonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 22:25:51 by lsimonne          #+#    #+#             */
/*   Updated: 2015/02/27 22:27:40 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_char(const char *s, char car)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i] != car && s[i])
			i++;
		return (i);
	}
	return (0);
}
