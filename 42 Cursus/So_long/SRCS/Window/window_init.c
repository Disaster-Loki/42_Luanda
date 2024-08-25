/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:32:26 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/25 10:32:29 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	*get_img_path(void *mlx, char c)
{
	int		x;
	int		y;
	void	*img;

	x = 0;
	y = 0;
	if (c == '1')
		img = mlx_xpm_file_to_image(mlx, "./SRCS/Images/walk.xpm", &x, &y);
	if (c == 'P')
		img = mlx_xpm_file_to_image(mlx, "./SRCS/Images/Player.xpm", &x, &y);
	if (c == '0')
		img = mlx_xpm_file_to_image(mlx, "./SRCS/Images/Path.xpm", &x, &y);
	if (c == 'C')
		img = mlx_xpm_file_to_image(mlx, "./SRCS/Images/coin.xpm", &x, &y);
	if (c == 'E')
		img = mlx_xpm_file_to_image(mlx, "./SRCS/Images/Exit.xpm", &x, &y);
	return (img);
}

void	print_map_window(void *mlx, void *win, char **map)
{
	int		i;
	int		j;
	void	*img;
	int		width;
	int		height;

	i = -1;
	width = 0;
	height = 0;
	while (map[++i])
	{
		j = -1;
		width = 0;
		while (map[i][++j])
		{
			img = get_img_path(mlx, map[i][j]);
			mlx_put_image_to_window(mlx, win, img, width, height);
			mlx_destroy_image(mlx, img);
			width += 32;
		}
		height += 27;
	}
}

void	window_init(char **args)
{
	t_point		pos;
	t_windows	windows;
	char		*g_name;

	g_name = "SO LONG";
	windows.mlx = mlx_init();
	windows.map = get_map(args[1]);
	pos.y = ft_len_line(windows.map);
	pos.x = (int) ft_strlen(*(windows.map));
	windows.win = mlx_new_window(windows.mlx, pos.x * 32, pos.y * 27, g_name);
	mlx_key_hook(windows.win, keypress, &windows);
	print_map_window(windows.mlx, windows.win, windows.map);
	mlx_loop(windows.mlx);
}
