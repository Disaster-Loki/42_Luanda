#include "../../inc/so_long.h"

void	validate_string(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '\n')
		error("Error - Invalid line\n", 1);
	while (str[++i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			error("Error - Invalid line\n", 1);
	}
	if (str[i] == '\0' && str[i-1] == '\n')
		error("Error - Invalid line\n", 1);
}