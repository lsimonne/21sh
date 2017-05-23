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

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "execute_syntax_tree.h"
# include <libft.h>

/*
** FILE_PERMISSION same as 644
*/

# define FILE_PERMISSION (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

int				*save_stdin_stdout();
t_error_id		redirect(t_redirection *redirections, int *backup);
void			restore_stdin_stdout(int *std);

#endif
