/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:16:51 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/23 14:16:55 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	validate_single_character(char *str)
{
	if (single_character(str, 'P') == -1)
		error("Error - No players\n", 1);
	if (single_character(str, 'E') == -1)
		error("Error - No way out\n", 1);
	if (single_character(str, 'C') == -1)
		error("Error - No collectibles\n", 1);
	if (!single_character(str, 'P'))
		error("Error - character more than 1 occurrence\n", 1);
	if (!single_character(str, 'E'))
		error("Error - character more than 1 occurrence\n", 1);
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
