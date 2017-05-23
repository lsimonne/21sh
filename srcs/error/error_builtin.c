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
#include "libft.h"
#include "shell_env.h"

static void		ft_putstr_colon(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
}

void			error_builtin(char *builtin, char *error, t_error_id id)
{
	set_error(id);
	ft_putstr_colon(SHNAME);
	if (builtin)
		ft_putstr_colon(builtin);
	if (error)
	{
		ft_putstr_colon(error);
		ft_strdel(&error);
	}
	print_error_msg(id);
	if (id == INVALID_OPTION)
	{
		ft_putstr_colon(builtin);
		ft_putstr_colon("usage");
		print_usage_msg(HISTORY_BUID);
	}
}
