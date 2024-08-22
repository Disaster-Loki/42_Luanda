#include "../../inc/so_long.h"

void	validate_single_character(char *str)
{
	if (!single_character(str, 'P'))
		error("Error - character more than 1 occurrence\n",1);
	if (!single_character(str, 'E'))
		error("Error - character more than 1 occurrence\n",1);
}

void	validate_string(char *str)
{
	if (*str == '\n')
		error("Error - Invalid line !!\n", 1);
	while (*str)
	{
		if (*str == '\n' && *(str + 1) == '\n')
			error("Error - Invalid line !!\n", 1);
		str++;
	}
	if (*str == '\0' && *(str - 1) == '\n')
		error("Error - Invalid line !!\n", 1);
}