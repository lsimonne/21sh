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

#include "errors.h"

static t_error_id		*get_error_ptr(void)
{
	static t_error_id	error;

	return (&error);
}

t_error_id				get_error(void)
{
	return (*get_error_ptr());
}

void					set_error(t_error_id error)
{
	*(get_error_ptr()) = error;
}
