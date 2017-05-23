/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <lsimonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 18:21:46 by lsimonne          #+#    #+#             */
/*   Updated: 2015/02/18 18:22:37 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_char(char **tab, int i, int j)
{
	char *tmp;

	tmp = ft_strdup(tab[i]);
	free(tab[i]);
	tab[i] = ft_strdup(tab[j]);
	free(tab[j]);
	tab[j] = ft_strdup(tmp);
	free(tmp);
}
