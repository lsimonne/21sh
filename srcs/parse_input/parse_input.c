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
	if (get_error() != NO_ERROR && get_error() != sh_env->last_unmatched)
	{
		ft_strdel(&get_shell_env()->input_string);
		print_name_and_error(get_error());
	}
	delete_all_tokens(&sh_env->tokens);
#ifdef FTSH_DEBUG
	ft_putendl("<syntax_tree>");
	print_command_list(sh_env->syntax_tree, 0);
	ft_putendl("</syntax_tree>");
#endif
}
