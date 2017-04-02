#include <libft.h>
#include <stdbool.h>
#include "utils.h"
#include "uint.h"

char	*str_in_str(char *find, char *str, t_uint from, bool must_start)
{
	char	*start;

	if (must_start)
	{
		start = str;
		if (ft_strnequ(start, find, ft_strlen(find)))
			return (start);
	}
	else
	{
		while ((start = ft_strchr(&str[from], *find)))
		{
			if (ft_strnequ(start, find, ft_strlen(find)))
				return (start);
			from = start - str + 1;
		}
		return (NULL);
	}
	return (NULL);
}