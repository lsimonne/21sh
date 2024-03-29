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

#include "read_input/editor/editor.h"
#include <libft.h>

static void	highlighted_core(char *line, size_t cur, size_t start, size_t len)
{
	char *begin;
	char *middle;
	char *end;

	begin = NULL;
	middle = NULL;
	end = NULL;
	if (start && cur >= start)
	{
		begin = ft_strsub(line, 0, start);
		middle = ft_strsub(line, start, cur - start);
		end = ft_strsub(line, cur, len - cur);
	}
	else if (start && cur < start)
	{
		begin = ft_strsub(line, 0, cur);
		middle = ft_strsub(line, cur, start - cur);
		end = ft_strsub(line, start, len - start);
	}
	ft_putstr(begin);
	ft_putstrc(4, 3, middle);
	ft_putstr(end);
	free(begin);
	free(middle);
	free(end);
}

void		put_highlighted_line(t_editor *ed, char *line)
{
	size_t	cur;
	size_t	start;
	size_t	offset;
	size_t	len;

	len = ft_strlen(line);
	if (!line || len <= 0)
		return ;
	offset = ft_strlen(ed->prompt);
	start = ed->selected_string_start + offset;
	cur = ed->cursor_position + offset;
	if (ed->in_selection)
	{
		highlighted_core(line, cur, start, len);
	}
	else
	{
		ft_putstr(line);
	}
}
