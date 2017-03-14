#ifndef TOKEN_DEF_H
# define TOKEN_DEF_H

# include "token_id.h"
# include <stdbool.h>

typedef struct				s_token_def
{
	t_token_id const	id;
	char const *const	name;
	char const *const	str;
}							t_token_def;

# define TOKEN_DEF_COUNT 12

t_token_def const			*get_token_def(t_token_id id);
t_token_def const			*get_token_defs(void);

t_token_def const			*get_matching_operator(char const *str);

void						print_token_def(t_token_def const *def);
void						print_token_defs(void);



#endif
