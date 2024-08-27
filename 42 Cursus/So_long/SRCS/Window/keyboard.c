/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:26:47 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/25 13:26:49 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	get_count_steps(t_game *game)
{
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(game->count, 1);
	ft_putchar_fd('\n', 1);
}

void	get_alter_position(t_game *game, t_point begin, int x, int y)
{
	if (game->map[begin.x + x][begin.y + y] == 'C')
		game->c_tibles++;
	if (game->map[begin.x + x][begin.y + y] != '1'
		&& game->map[begin.x + x][begin.y + y] != 'E')
	{
		game->map[begin.x][begin.y] = '0';
		game->map[begin.x + x][begin.y + y] = 'P';
		game->count++;
		get_count_steps(game);
		print_map_window(game);
	}
	if ((game->map[begin.x + x][begin.y + y] == 'E')
		&& (game->t_tibles == game->c_tibles))
		close_game(game);
}

int	keypress(int key, t_game *game)
{
	int		esc;
	t_point	begin;

	esc = 65307;
	begin = begin_position(game->map, 'P');
	if (key == 'w')
		get_alter_position(game, begin, -1, 0);
	if (key == 's')
		get_alter_position(game, begin, 1, 0);
	if (key == 'd')
	{
		game->flag = 0;
		get_alter_position(game, begin, 0, 1);
	}
	if (key == 'a')
	{
		game->flag = 1;
		get_alter_position(game, begin, 0, -1);
	}
	if (key == esc)
		close_game(game);
	return (1);
}
