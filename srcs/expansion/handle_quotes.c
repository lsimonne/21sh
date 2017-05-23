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

void		handle_quotes(char c, char *quoted)
{
	if (c == '\'')
	{
		if (*quoted & IS_QU_SIMPLE)
			*quoted -= IS_QU_SIMPLE;
		else
			*quoted |= IS_QU_SIMPLE;
	}
	else if (c == '\"')
	{
		if (*quoted & IS_QU_DOUBLE)
			*quoted -= IS_QU_DOUBLE;
		else
			*quoted |= IS_QU_DOUBLE;
	}
}
