/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimonne <lsimonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:35:21 by lsimonne          #+#    #+#             */
/*   Updated: 2017/05/04 15:35:21 by lsimonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#define N_ERRNO 133
#define N_ERRNO_BASE 34

char const	*get_system_error(int signum)
{
	static char const *errno_base_defs[N_ERRNO_BASE + 1] =
	{"None", "Operation not permitted", "No such file or directory",
	"No such process", "Interrupted system call", "I/O error", \
	"No such device or address",
	"Argument list too long", "Exec format error", "Bad file number",
	"No child processes", "Try again", "Out of memory", "Permission denied",
	"Bad address", "Block device required", "Device or resource busy",
	"File exists", "Cross-device link", "No such device", "Not a directory",
	"Is a directory", "Invalid argument", "File table overflow",
	"Too many open files", "Not a typewriter", "Text file busy",
	"File too large", "No space left on device", "Illegal seek",
	"Read-only file system", "Too many links", "Broken pipe",
	"Math argument out of domain of func", "Math result not representable",
	};

	if (signum >= 0 && signum <= N_ERRNO_BASE)
	{
		return (errno_base_defs[signum]);
	}
	return ("");
}
