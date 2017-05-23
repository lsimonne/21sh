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

#include "utils.h"
#include <stdlib.h>
#include <libft.h>

char			*strdup_until(char const *src, char const *stop)
{
	char	*result;
	size_t	len;

	len = stop - src;
	result = memalloc_or_die(sizeof(char) * (len + 1));
	ft_strncpy(result, src, len);
	result[len] = '\0';
	return (result);
}
