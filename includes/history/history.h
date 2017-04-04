#ifndef HISTORY_H
# define HISTORY_H

#include "execution/builtins/builtin_def.h"
#include "shell_env.h"

# include "execution/builtins/builtin_def.h"


/*
**exported env variable in shells - need absolute path !
*/
# define HISTFILE ".42sh_history"

/*
**		load_history.c
*/
void				load_history(t_shell_env *shell_env, char *filename, int position);
void				add_to_history_list(t_history **list, t_history *new);
t_history			*create_history_entry(char *line);


/*
**		print_history.c
*/


void			print_history(t_history *history, int start);
void			print_history_n(bool more_args, char *n, t_history *history);

/*
**		history_del.c
*/

void			clear_history_list(t_history **history);
void			delete_history_entry(t_history **history, char *offset);


/*
**		history_to_file.c
*/

void			hist_to_file(t_history *history, char *filename, bool append);

#endif