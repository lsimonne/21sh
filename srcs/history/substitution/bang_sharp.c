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

#include "history_substitutions.h"

void		bang_sharp(char **str, t_uint *i, int *should_run)
{
	char *tmp;

	if (*i > 0)
		*should_run = start_substitution(str, i, ft_strsub(*str, 0, *i));
	else if (ft_strlen(*str) > 2)
	{
		tmp = ft_strsub(*str, 2, ft_strlen(*str) - 2);
		ft_strdel(str);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else
	{
		ft_strdel(str);
		*str = ft_strdup("\n");
	}
}
