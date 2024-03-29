/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <lsimonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 10:26:12 by lsimonne          #+#    #+#             */
/*   Updated: 2015/05/01 13:31:26 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (s && ft_strlen(s) > 0)
	{
		while (i <= ft_strlen(s))
		{
			if (s[i] == c)
				return ((char*)s + i);
			i++;
		}
	}
	return (NULL);
}
