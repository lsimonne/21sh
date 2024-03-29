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
#include "utils.h"

char	*array_to_str(char **array)
{
	char	*str;
	char	*tmp;
	size_t	i;

	i = 0;
	str = NULL;
	if (!array)
		return (NULL);
	while (array[i])
	{
		if (str)
		{
			tmp = ft_strdup(str);
			ft_strdel(&str);
			str_add_space(&tmp);
		}
		else
			tmp = ft_strnew(1);
		str = ft_strjoin(tmp, array[i]);
		ft_strdel(&tmp);
		i++;
	}
	return (str);
}
