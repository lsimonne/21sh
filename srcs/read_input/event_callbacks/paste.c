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

#include "event_callback_def.h"

EV_CB_RET	ev_paste(t_editor *ed)
{
	size_t i;

	i = -1;
	if (ed->selected_string)
	{
		ed->pos = get_cursor_vector(ed);
		while (ed->selected_string[++i])
		{
			add_to_string(ed, ed->selected_string[i]);
		}
	}
}
