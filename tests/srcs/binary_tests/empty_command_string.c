#include "test_utils.h"

void	empty_command_string()
{
	int status = call_42sh("-c \"\"");
	CU_ASSERT(status == EXIT_SUCCESS);
}
