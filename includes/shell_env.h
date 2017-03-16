#ifndef GLOBAL_H
# define GLOBAL_H

# include <stdlib.h>
# include <libft.h>
# include <stdbool.h>
# include "break_input/tokenizer/token.h"

/* proposition

typedef struct 			s_history
{
	size_t			size;
	t_history_list	*last_elem
	t_history_list	*history_list;
}

OR liste circulaire

*/

typedef struct			s_history
{
	struct s_history	*next;
	char				*line;
	bool				appended;
	struct s_history	*prev;
}						t_history;

typedef struct			s_variable
{
	struct s_variable	*next;
	char				*name;
	char				*value;
	bool				exported;
}						t_variable;

typedef struct			s_shell_env
{
	t_variable			*variables;
	t_history			*history;
	bool				should_run;
	bool				should_keep_reading;
	char				*command_string;
	char				*input_string;
	t_token				*tokens;
}						t_shell_env;

t_shell_env				*get_shell_env(void);

#endif
