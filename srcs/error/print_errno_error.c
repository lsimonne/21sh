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

#include <libft.h>
#include <errno.h>
#include "errors.h"

void		print_errno_error(int err, char const *pre, char const *post)
{
	ft_putstr_fd("42sh: ", 2);
	if (pre != NULL)
	{
		ft_putstr_fd(pre, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(get_system_error(err), 2);
	if (post != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(post, 2);
	}
	ft_putchar_fd('\n', 2);
}
