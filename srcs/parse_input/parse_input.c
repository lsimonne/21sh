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
#include "parse_syntax_tree.h"
#include "print_syntax_tree.h"
#include "ftsh.h"
#include "errors.h"

void			parse_input(void)
{
	t_shell_env	*sh_env;

	set_error(NO_ERROR);
	sh_env = get_shell_env();
	sh_env->syntax_tree = parse_command_list(sh_env->tokens);
	if (get_error() != NO_ERROR && get_error() != sh_env->last_unmatched
		&& sh_env->command_string == NULL)
	{
		ft_strdel(&get_shell_env()->input_string);
		print_name_and_error(get_error());
	}
	delete_all_tokens(&sh_env->tokens);
}
