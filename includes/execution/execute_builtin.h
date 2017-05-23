#ifndef EXECUTE_BUILTIN_H
#define EXECUTE_BUILTIN_H

void 	reset_env(t_simple_command *cmd, t_variable *env_backup);
void	set_env_exec(t_variable **env_backup, t_variable *assignments);

#endif
