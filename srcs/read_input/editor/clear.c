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
#include "read_input/event_callbacks/event_callback_def.h"

void	clear_line(t_editor *ed)
{
	move_start(ed);
	ft_putstr(ed->term->clear_line);
	ed->pos = get_cursor_vector(ed);
}

void	free_editor(t_editor *ed)
{
	free_string(ed->string);
	free(ed->prompt);
	free(ed->term);
}
