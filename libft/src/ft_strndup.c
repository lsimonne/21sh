/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <lsimonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 15:30:30 by lsimonne          #+#    #+#             */
/*   Updated: 2015/03/08 15:35:40 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (s1)
	{
		i = ft_strlen(s1);
		if (i < len)
			str = (char *)memalloc_or_die(sizeof(char) * (i + 1));
		else
			str = (char *)memalloc_or_die(sizeof(char) * (len + 1));
		i = -1;
		while (s1[++i] && i < len)
			str[i] = s1[i];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
