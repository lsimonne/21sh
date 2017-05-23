/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <lsimonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 16:39:48 by lsimonne          #+#    #+#             */
/*   Updated: 2015/05/31 17:47:01 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_char(char *str, char car)
{
	int i;
	int nbr;

	if (str)
	{
		nbr = 0;
		i = -1;
		while (str[++i])
		{
			if (str[i] == car)
				nbr++;
		}
		return (nbr);
	}
	return (0);
}
