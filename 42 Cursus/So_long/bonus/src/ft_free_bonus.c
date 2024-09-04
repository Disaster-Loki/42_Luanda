/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:42:54 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/23 14:42:57 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	if (map)
	{
		i = -1;
		while (map[++i])
			free(map[i]);
		free(map);
	}
}

void	free_matrix(int **matrix, int rows)
{
	int	i;

	if (matrix)
	{
		i = -1;
		while (++i < rows)
			free(matrix[i]);
		free(matrix);
	}
}
