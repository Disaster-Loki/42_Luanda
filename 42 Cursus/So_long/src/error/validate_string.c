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

void	valid_img_path(t_game *game, t_img *img)
{
	if (!img->player[0] || !img->player[1]
		|| !img->player[2] || !img->player[3] || !img->wall
		|| !img->coin || !img->exit || !img->path)
	{
		window_stop(game);
		error("Error - Error loading the image !!\n");
	}
}

void	validate_single_character(char *str)
{
	if (single_character(str, 'P') == -1)
		error_str("Error - No players\n", str);
	if (single_character(str, 'E') == -1)
		error_str("Error - No way out\n", str);
	if (single_character(str, 'C') == -1)
		error_str("Error - No collectibles\n", str);
	if (!single_character(str, 'P'))
		error_str("Error - More than one P on the map\n", str);
	if (!single_character(str, 'E'))
		error_str("Error - More than one E on the map\n", str);
}

void	validate_string(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		error_str("Error - Invalid line !!\n", str);
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			error_str("Error - Invalid line !!\n", str);
		i++;
	}
	if (str[i] == '\0' && str[i - 1] == '\n')
		error_str("Error - Invalid line !!\n", str);
}
