/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <lsimonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 14:07:16 by lsimonne          #+#    #+#             */
/*   Updated: 2015/05/01 15:03:03 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double x, double y)
{
	double ret;
	double i;

	i = 0;
	ret = x;
	while (++i < y)
		ret *= x;
	return (ret);
}
