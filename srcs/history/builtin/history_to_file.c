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

#include "shell_env.h"
#include "history.h"
#include <errno.h>
#include "errors.h"

/*
**	-a appends entries not already appended
**	-w overwrites or creates file
**	if filename is specified, write to file
*/

void	hist_to_file(t_history *history, char *filename, bool append)
{
	int		fd;

	if (append)
		fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, FILE_PERMISSION);
	else
		fd = open(filename, O_TRUNC | O_WRONLY | O_CREAT, FILE_PERMISSION);
	if (fd > 0)
	{
		while (history)
		{
			if (!append || !history->appended)
			{
				history->appended = true;
				ft_putstr_fd(history->line, fd);
			}
			history = history->next;
		}
		close(fd);
	}
	else
	{
		print_errno_error(errno, "history", filename);
		set_error(1);
	}
}
