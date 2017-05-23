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

#ifndef TOKEN_ID_H
# define TOKEN_ID_H

typedef enum	e_token_id
{
	TOKEN_TOKID = 0,
	WORD_TOKID,
	ASSIGNMENT_WORD_TOKID,
	NEWLINE_TOKID,
	IO_NUMBER_TOKID,
	SEMI_TOKID,
	OR_TOKID,
	LESS_TOKID,
	DLESS_TOKID,
	GREAT_TOKID,
	AND_IF_TOKID,
	OR_IF_TOKID,
	DGREAT_TOKID
}				t_token_id;

#endif
