/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canonicalize_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 22:02:05 by lsimonne          #+#    #+#             */
/*   Updated: 2017/05/23 22:02:09 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/builtins/builtins.h"
#include "variable.h"
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "uint.h"
#include "errors.h"
#include <errno.h>
#include "utils.h"
#include "strlist.h"

bool			comp_is_dot(char const *comp)
{
	if (ft_strnequ(comp, "./", 2) || ft_strequ(comp, "."))
		return (true);
	else
		return (false);
}

bool			comp_is_dot_dot(char const *comp)
{
	if (ft_strnequ(comp, "../", 3) || ft_strequ(comp, ".."))
		return (true);
	else
		return (false);
}

void			remove_dots(t_strlist **cmpnts_addr)
{
	t_strlist	*component;

	component = *cmpnts_addr;
	while (component != NULL)
	{
		if (comp_is_dot(component->str))
		{
			*cmpnts_addr = component->next;
			component->next = NULL;
			strlist_delete(&component);
		}
		else
		{
			cmpnts_addr = &component->next;
		}
		component = *cmpnts_addr;
	}
}
