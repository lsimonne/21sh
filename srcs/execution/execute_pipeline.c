#include "parse_input/syntax_tree.h"
#include "errors.h"
#include "utils.h"
#include <libft.h>
#include "execute_syntax_tree.h"
#include "pipe.h"
#include <stdio.h>
#include "redirection.h"
#include "expansion/expansion.h"
#include "errno.h"

t_error_id	execute_file(t_simple_command *cmd, size_t lvl)
{
	(void)lvl;
	t_error_id	ret;

#ifdef FTSH_DEBUG
	print_n_char_fd(' ', (lvl) * 2, 2);
	dprintf(2, "executing file %s\n", cmd->argv[0]);
#endif
	if (enter_subshell() == FORKED_IN_CHILD)
	{
		execvp(cmd->argv[0], cmd->argv);
#ifdef FTSH_DEBUG
		print_n_char_fd(' ', (lvl + 1) * 2, 2);
#endif
		print_errno_error(errno, cmd->argv[0], NULL);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait_for_childs();
		ret = get_error();
	}
#ifdef FTSH_DEBUG
	print_n_char_fd(' ', (lvl) * 2, 2);
	dprintf(2, "done executing file %s, %s\n", cmd->argv[0], ret == NO_ERROR ? "ok" : "error");
#endif
	return (ret);
}

t_error_id	execute_simple_command(t_simple_command *cmd, size_t lvl)
{
	t_error_id	ret;
	extern char	**environ;
	char		**environ_backup;
	int 		*stdin_out_backup;

	ret = NO_ERROR;
	if (cmd != NULL)
	{
#ifdef FTSH_DEBUG
		print_n_char_fd(' ', (lvl) * 2, 2);
		dprintf(2, "executing simple command %s\n", cmd->argv[0]);
		// EXECUTION CORE
		print_n_char_fd(' ', (lvl + 1) * 2, 2);
		dprintf(2, "expanding simple command %s\n", cmd->argv[0]);
#endif
		expand_cmd_words(&cmd->argv);
#ifdef FTSH_DEBUG
		print_n_char_fd(' ', (lvl + 1) * 2, 2);
		dprintf(2, "done expanding simple command %s\n", cmd->argv[0]);
#endif
		stdin_out_backup = save_stdin_stdout();
		ret = redirect(cmd->redirections);
		//expand_assignments_values(cmd->assignments);
		if (ret != NO_ERROR)
			return (ret);
		environ_backup = environ;
		environ = get_variables_for_execution(cmd->assignments);
		ret = execute_builtin(cmd, lvl + 1);
		if (ret == NO_SUCH_BUILTIN)
			ret = execute_file(cmd, lvl + 1);
		ft_freetabchar(environ);
		environ = environ_backup;

		restore_stdin_stdout(stdin_out_backup);
#ifdef FTSH_DEBUG
		print_n_char_fd(' ', (lvl) * 2, 2);
		dprintf(2, "done executing simple command %s, %s\n", cmd->argv[0], ret == NO_ERROR ? "ok" : "error");
#endif
	}
	return (ret);
}

t_error_id	execute_pipeline(t_simple_command *pipeline, size_t lvl)
{
	t_error_id			ret;
	t_pipeline_state	pipeline_state;

	if (pipeline == NULL)
		return (NO_ERROR);
	if (pipeline->next == NULL)
		return (execute_simple_command(pipeline, lvl));
#ifdef FTSH_DEBUG
	print_n_char_fd(' ', (lvl) * 2, 2);
	dprintf(2, "executing pipeline\n");
#endif
	ft_bzero(&pipeline_state, sizeof(t_pipeline_state));
	ret = NO_ERROR;
	while (pipeline != NULL)
	{
		if (pipeline->next == NULL)
			pipeline_state.last_cmd = true;
		if (pipe_me_in(&pipeline_state) == FORKED_IN_CHILD)
		{
			ret = execute_simple_command(pipeline, lvl + 1);
			if (ret == NO_ERROR)
				exit(EXIT_SUCCESS);
			else
				exit(EXIT_FAILURE);
		}
		pipeline = pipeline->next;
	}
	wait_for_childs();
#ifdef FTSH_DEBUG
	print_n_char_fd(' ', (lvl) * 2, 2);
	dprintf(2, "done executing pipeline, %s\n", pipeline_state.last_ret == NO_ERROR ? "ok" : "error");
#endif
	return (ret);
}
