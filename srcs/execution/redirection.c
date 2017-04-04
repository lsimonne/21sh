#include "redirection.h"

#define REDIRECT_DEBUG

int 				*save_stdin_stdout()
{
	static int std[2];

	std[0] = dup(STDIN_FILENO);
	std[1] = dup(STDOUT_FILENO);
	return (std);
}

void				restore_stdin_stdout(int *std)
{
	dup2(std[0], STDIN_FILENO);
	close(std[0]);
	dup2(std[1], STDOUT_FILENO);
	close(std[1]);
}

int 				choose_open(t_redir_type type, char *file)
{
	if (type == REDIR_OUTPUT)
		return(open(file, O_RDWR | O_CREAT | O_TRUNC, 0666));
	else if (type == APPEND_OUTPUT)
		return(open(file, O_RDWR | O_CREAT | O_APPEND, 0666));
	else
		return(open(file, O_RDONLY));
}

t_error_id			redirect(t_redirection *redirections)
{
	t_error_id 	ret;
	int 		file_fd;

	ret = NO_ERROR;
	while (redirections)
	{
		file_fd = choose_open(redirections->type, redirections->word);
		if (file_fd < 0)
		{
			set_file_error(redirections->word);
			ret = get_error();
			print_file_error(ret, redirections->word);
			return (ret);
		}
		else
		{
			dup2(file_fd, redirections->n);
			close(file_fd);
		}
		redirections = redirections->next;
	}
	return (ret);
}