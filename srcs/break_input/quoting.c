#include "quoting.h"
#include <libft.h>

static char const *find_simple_quote_end(t_tokenizer_state *state)
{
	char const *it;

	it = state->current_char + 1;
	while (*it != '\0')
	{
		if (*it == '\'')
			return (it);
		it++;
	}
	ft_putendl_fd("42sh: syntax error: missing simple quote end\n", 2);
	exit(1);
}

void			apply_quoting(t_tokenizer_state *state)
{
	if (*state->current_char == '\\')
		state->last_backslash = state->current_char;
	else if (*state->current_char == '\'')
		state->simple_quote_end = find_simple_quote_end(state);
	else if (*state->current_char == '"')
		state->double_quote_end = find_double_quote_end(state);
}

bool			is_quoted(t_tokenizer_state *state)
{
	if (state->last_backslash != NULL
		&& (state->current_char == state->last_backslash
				|| state->current_char - 1 == state->last_backslash))
		return (true);
	if (state->simple_quote_end >= state->current_char)
		return (true);
	if (is_double_quoted(state))
		return (true);
	return (false);
}

bool			is_quote(char c)
{
	if (c == '\'' || c == '"' || c == '\\')
		return (true);
	return (false);
}
