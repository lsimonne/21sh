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

#include "utils.h"

#include "uint.h"
#include <stdlib.h>
#include <libft.h>
#include "variable.h"

static t_uchar	*get_ptr(void)
{
	static t_uchar	last_exit_status = EXIT_SUCCESS;

	return (&last_exit_status);
}

t_uchar			get_last_exit_status(void)
{
	return (*get_ptr());
}

void			set_last_exit_status(t_uchar status)
{
	char *st;

	st = ft_itoa(status);
	set_variable("?", st, false);
	free(st);
	*get_ptr() = status;
}
