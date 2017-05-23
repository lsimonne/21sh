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

#ifndef EXECUTE_PIPELINE_H
# define EXECUTE_PIPELINE_H

t_error_id	execute_file(t_simple_command *cmd, size_t lvl);
t_error_id	execute_simple_command(t_simple_command *cmd, size_t lvl);
t_error_id	execute_pipeline(t_simple_command *pipeline, size_t lvl);

#endif
