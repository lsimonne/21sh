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

#include "read_input/editor/editor_struct.h"
#include "abstract_list.h"

t_string	*str_to_list(char *str)
{
	t_string	*l_str;
	t_string	*new;
	int			i;

	i = 0;
	l_str = NULL;
	while (str && str[i])
	{
		new = memalloc_or_die(sizeof(t_string));
		new->c = str[i];
		new->next = NULL;
		list_push_back((t_abstract_list **)&l_str, (t_abstract_list *)new);
		i++;
	}
	return (l_str);
}
