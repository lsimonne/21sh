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

#include <stdbool.h>
#include <libft.h>
#include "errors.h"
#include "shell_env.h"

bool		is_substitution_start(char const *s)
{
	if (s && *s && *s == '`')
		return (true);
	return (false);
}

char const	*find_substitution_end(char const *str)
{
	set_error(NO_ERROR);
	while (*str)
	{
		if (*str == '\\' && (*(str + 1) == '`' || *(str + 1) == '\\'))
			str++;
		else if (*str == '`')
			return (str);
		str++;
	}
	set_error(UNMATCHED_BACKQUOTE);
	get_shell_env()->last_unmatched = UNMATCHED_BACKQUOTE;
	return (NULL);
}
