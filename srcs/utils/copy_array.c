/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <lsimonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:35:21 by lsimonne          #+#    #+#             */
/*   Updated: 2017/05/04 15:35:21 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			**copy_array(char **array, size_t start, int end)
{
	char	**copy;
	size_t	i;
	size_t	size;

	i = 0;
	size = end - start;
	copy = NULL;
	if (size)
	{
		copy = (char **)memalloc_or_die(sizeof(char *) * (size + 1));
		copy[size] = NULL;
		while (i < size)
		{
			copy[i] = ft_strdup(array[start]);
			i++;
			start++;
		}
	}
	return (copy);
}
