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

#include "abstract_list.h"
#include <stdbool.h>

bool		list_goto_n(t_abstract_list **list, t_uint n)
{
	while ((*list) && n > 0)
	{
		(*list) = (*list)->next;
		n--;
	}
	if (!(*list))
		return (false);
	return (true);
}
