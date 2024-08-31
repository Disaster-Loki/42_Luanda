/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_enemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:01:38 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/30 12:01:40 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	get_alter_position_enemies(t_game *game, t_point *begin, int x, int y)
{
	char	move;

	move = game->map[begin->x + x][begin->y + y];
	if (move == 'P')
		game_over(game, move);
	if (move == '0')
	{
		game->map[begin->x][begin->y] = '0';
		game->map[begin->x + x][begin->y + y] = 'I';
		begin->x =  begin->x + x;
		begin->y =  begin->y + y;
		return (1);
	}
	return (0);
}

void	move_enemy(t_game *game, t_point pos)
{
	usleep(1000);
	if (game->move >= 0 && game->move < 4)
	{
		get_alter_position_enemies(game, &pos, 0, -1);
	}
	else if (game->move >= -4 && game->move < 0)
	{
		get_alter_position_enemies(game, &pos, 0, 1);
	}
	game->move++;
	if (game->move == 4)
		game->move *= -1;
	printf("Move: %d\n", game->move);
}

void	get_move_enimy(t_game *game, t_point pos, int i, int j)
{
	while (++i < ft_len_line(game->map))
	{
		j = -1;
		while (++j < (int) ft_strlen(game->map[0]))
		{
			if (game->map[i][j] == 'I')
			{
				pos.x = i;
				pos.y = j;
				move_enemy(game, pos);
			}
		}
	}
}

int	manipulate_enemies(t_game *game)
{
	static int	frame_count;
	t_point		pos;
	int			i;
	int			j;

	frame_count++;
	pos.x = 0;
	pos.y = 0;
	if (frame_count >= 100)
	{
		i = -1;
		j = 0;
		frame_count = 0;
		game->frame = (game->frame + 1) % 4;
		get_move_enimy(game, pos, i, j);
		print_map_window(game);
	}
	usleep(10000);
	return (0);
}
