//   By: Evelina-Svitlana Protsenko 

#include "../include/minihell.h"

int	handle_middle_file_in(t_cmd_info *tcmd)
{
	if (tcmd->file_in == NULL)
		return (0);
	if (access(tcmd->file_in, F_OK) == 0)
	{
		if (access(tcmd->file_in, R_OK) != 0)
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
	return (0);
}
