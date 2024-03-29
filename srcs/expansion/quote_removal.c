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
#include "abstract_list.h"
#include "utils.h"
#include "break_input/quoting.h"
#include "expansion.h"

static void	remove_backslash(t_string **l_addr, t_string **l_str, \
								bool *quoted, size_t *pos)
{
	if (!quoted[0] && (quoted[1] && (*l_str)->next && \
		((*l_str)->next->c == '\"' || (*l_str)->next->c == '\\')))
	{
		*l_str = (*l_str)->next;
		list_pop_at_pos(*pos, (t_abstract_list **)l_addr);
	}
	else if (!quoted[0] && !quoted[1])
	{
		list_pop_at_pos(*pos, (t_abstract_list **)l_addr);
		*l_str = (*l_str)->next;
	}
}

static void	remove_quote(t_string **l_addr, char c, bool *quoted, size_t *pos)
{
	size_t			i;
	char const		*quotes;

	quotes = "\'\"";
	i = ft_strchr(quotes, c) - quotes;
	if (!quoted[!i])
	{
		list_pop_at_pos(*pos, (t_abstract_list **)l_addr);
		(*pos)--;
		quoted[i] = !quoted[i];
	}
}

static void	remove_quotes(t_string **l_addr)
{
	bool			quoted[2];
	size_t			pos;
	t_string		*l_str;

	ft_bzero(quoted, sizeof(bool) * 2);
	l_str = *l_addr;
	pos = 0;
	while (l_str)
	{
		if (is_quote(l_str->c))
		{
			if (l_str->c == '\\')
				remove_backslash(l_addr, &l_str, quoted, &pos);
			else
				remove_quote(l_addr, l_str->c, quoted, &pos);
		}
		pos++;
		l_str = l_str->next;
	}
}

static bool	has_quotes(char *str)
{
	while (*str)
	{
		if (is_quote(*str))
			return (true);
		str++;
	}
	return (false);
}

void		quote_removal(char **word)
{
	t_string		*l_str;

	if (has_quotes(*word))
	{
		l_str = str_to_list(*word);
		remove_quotes(&l_str);
		ft_strdel(word);
		*word = get_string_from_list(l_str);
		free_string(l_str);
	}
}
