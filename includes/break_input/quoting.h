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

#ifndef QUOTING_H
# define QUOTING_H

# include "tokenizer_state.h"

bool		is_quote(char c);
void		apply_quoting(t_tokenizer_state *state);
bool		is_quoted(t_tokenizer_state *state);

bool		is_double_quoted(t_tokenizer_state *state);
char const	*find_double_quote_end(t_tokenizer_state *state);

#endif
