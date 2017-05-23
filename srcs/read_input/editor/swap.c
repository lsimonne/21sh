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

#include "read_input/event_callbacks/event_callback_def.h"
#include <libft.h>

void	swap_position_if_needed(t_editor *ed)
{
	size_t tmp;

	if (ed->selected_string_start > ed->selected_string_end)
	{
		tmp = ed->selected_string_start;
		ed->selected_string_start = ed->selected_string_end;
		ed->selected_string_end = tmp;
	}
}
