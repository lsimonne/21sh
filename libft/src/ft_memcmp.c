/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <lsimonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 18:28:05 by lsimonne          #+#    #+#             */
/*   Updated: 2014/11/28 11:40:45 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	int				res;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if ((s1 && s2))
	{
		i = 0;
		while (i < n)
		{
			if (str1[i] != str2[i])
			{
				res = (str1[i]) - (str2[i]);
				return (res);
			}
			i++;
		}
	}
	return (0);
}
