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

#include "expansion.h"
#include "strlist.h"
#include <stdlib.h>
#include <libft.h>
#include <stdio.h>
#include "range.h"
#include "utils.h"
#include "abstract_list.h"
#include "break_input/quoting.h"

static void	end_of_quote(char const *word, t_range *delimit)
{
	char	quote;

	quote = *word;
	delimit->end++;
	if (quote == '\\')
		return ;
	while (word[delimit->end] && (word[delimit->end] != quote \
			|| (word[delimit->end - 1] && word[delimit->end - 1] == '\\')))
		delimit->end++;
}

static void	skip_posix_blanks(char const *word, int *i)
{
	while (word[*i] && (is_posix_blank(word[*i]) || word[*i] == '\n'))
		(*i)++;
}

static void	add_field(char const *word, t_strlist **result, t_range *delimit)
{
	char		*tmp;

	tmp = ft_strsub(word, delimit->start, delimit->end - delimit->start);
	strlist_append(result, tmp);
	skip_posix_blanks(word, &delimit->end);
	delimit->start = delimit->end;
	ft_strdel(&tmp);
}

/*
**	scan the results of expansions and substitutions
** 	that did not occur in double-quotes and split into fields
*/

t_strlist	*field_splitting(char const *word)
{
	t_strlist	*result;
	t_range		delimit;
	t_strlist	*tmp;

	result = NULL;
	ft_bzero(&delimit, sizeof(t_range));
	while (word[delimit.start])
	{
		while (word[delimit.end] && !is_posix_blank(word[delimit.end]) \
				&& word[delimit.end] != '\n')
		{
			if (is_quote(word[delimit.end]))
				end_of_quote(&word[delimit.end], &delimit);
			delimit.end++;
		}
		add_field(word, &result, &delimit);
	}
	tmp = result;
	while (tmp)
		tmp = tmp->next;
	return (result);
}
