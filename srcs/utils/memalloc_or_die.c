#include <libft.h>

void	*memalloc_or_die(size_t size)
{
	void * m;

	m = malloc(size);
	if (!m)
	{
		ft_printf("Oh no! malloc is too heavy for me");
		exit(-1);
	}
	ft_bzero(m, size);
	return (m);
}
