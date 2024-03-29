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

#include "string_substitution.h"

void	take_out_backslashes(char **str, char delimiter)
{
	t_string	*l_str;
	t_string	*tmp;
	size_t		pos;

	if (ft_strchr(*str, '\\'))
	{
		pos = 0;
		l_str = str_to_list(*str);
		tmp = l_str;
		while (l_str)
		{
			if (l_str->c == '\\' && l_str->next && l_str->next->c == delimiter)
			{
				list_pop_at_pos(pos, (t_abstract_list **)&tmp);
				pos--;
			}
			pos++;
			l_str = l_str->next;
		}
		l_str = tmp;
		ft_strdel(str);
		*str = get_string_from_list(l_str);
		free_string(tmp);
	}
}

char	*next_unquoted(char *str, char c)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((tmp = ft_strchr(&str[i], c)) && *(tmp - 1) == '\\')
		i = tmp - str + 1;
	return (tmp);
}

char	*get_delimited_str(char *modifier, char delimiter, t_uint *i)
{
	char	*str;
	char	*tmp;
	size_t	len;

	if (!(tmp = next_unquoted(modifier, delimiter)))
	{
		len = ft_strlen(modifier);
		if (modifier[len - 1] == '\n')
			len--;
		str = ft_strsub(modifier, 0, len);
	}
	else
	{
		len = tmp - modifier;
		str = ft_strsub(modifier, 0, len);
	}
	take_out_backslashes(&str, delimiter);
	*i += len;
	return (str);
}
