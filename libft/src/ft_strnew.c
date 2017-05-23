/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <lsimonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:56:33 by lsimonne          #+#    #+#             */
/*   Updated: 2015/09/16 20:25:11 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	str = memalloc_or_die((sizeof(char) * (size + 1)));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		str[i++] = '\0';
	str[i] = '\0';
	return (str);
}
