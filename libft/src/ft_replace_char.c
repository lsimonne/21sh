/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <lsimonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 16:39:48 by lsimonne          #+#    #+#             */
/*   Updated: 2016/02/19 15:04:49 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace_char(char *line, char del, char add)
{
	int i;

	if (line)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] == del)
				line[i] = add;
		}
	}
}
