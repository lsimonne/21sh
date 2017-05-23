#include "utils.h"
#include <libft.h>
#include "variable.h"

void			set_env_exec(t_variable **env_backup, t_variable *assignments)
{
	*env_backup = copy_variable(get_shell_env()->variables);
	set_assignments(assignments, true);
}

static char		*get_backup_var(t_variable *env_backup, char *name)
{
	t_variable	*env;
	char		*val;

	val = NULL;
	env = get_shell_env()->variables;
	get_shell_env()->variables = env_backup;
	val = get_variable(name);
	if (!val && variable_exist(env_backup, name))
		val = ft_strnew(1);
	get_shell_env()->variables = env;
	return (val);
}

static void		restore_env(t_variable *env_backup, t_variable *assignments)
{
	char		*val;

	while (assignments)
	{
		val = get_backup_var(env_backup, assignments->name);
		if (val)
			setenv_as(&get_shell_env()->variables, \
						assignments->name, val, true);
		else
			unsetenv_as(&get_shell_env()->variables, assignments->name);
		ft_strdel(&val);
		assignments = assignments->next;
	}
}

void			reset_env(t_simple_command *cmd, t_variable *env_backup)
{
	if (!is_special_builtin(cmd->argv[0]))
		restore_env(env_backup, cmd->assignments);
	delete_all_variables(&env_backup);
}
