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

#include "../inc/so_long.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
}

char	**get_map(char *str)
{
	int		fd;
	int		size;
	char	*buffer;
	char	**map;

	fd = open(str, O_RDONLY);
	buffer = (char *)malloc(sizeof(char) * 1024);
	size = read(fd, buffer, 1024);
	buffer[size] = '\0';
	map = ft_split(buffer, '\n');
	return (map);
}

void	print_map_window(void*mlx, void *win, char **map)
{
	int		i;
	int		j;
	int	x = 0;
	int	y = 0;
	int 	width;
	int 	height;
	void	*img_path;

	i = -1;
	width = 0;
	height = 0;
	while (map[++i])
	{
		j = -1;
		width = 0;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
			{
				img_path = mlx_xpm_file_to_image(mlx, "./SRCS/Images/walk.xpm", &x, &y);
				mlx_put_image_to_window(mlx, win, img_path, width, height);
			}
			if (map[i][j] == 'P')
			{
				img_path = mlx_xpm_file_to_image(mlx, "./SRCS/Images/Player.xpm", &x, &y);
				mlx_put_image_to_window(mlx, win, img_path, width, height);
			}
			if (map[i][j] == '0')
			{
				img_path = mlx_xpm_file_to_image(mlx, "./SRCS/Images/Path.xpm", &x, &y);
				mlx_put_image_to_window(mlx, win, img_path, width, height);
			}
			if (map[i][j] == 'C')
			{
				img_path = mlx_xpm_file_to_image(mlx, "./SRCS/Images/coin.xpm", &x, &y);
				mlx_put_image_to_window(mlx, win, img_path, width, height);
			}
			if (map[i][j] == 'E')
			{
				img_path = mlx_xpm_file_to_image(mlx, "./SRCS/Images/Exit.xpm", &x, &y);
				mlx_put_image_to_window(mlx, win, img_path, width, height);
			}
			width += 83;
		}
		height += 56;
	}
	//mlx_destroy_image(mlx, img_path);
}

int	keypress(int key, t_windows *win)
{
	t_point	begin;

	begin = begin_position(win->map, 'P');
	if (key == 'w')
	{	
		//win->map[begin.x-1][begin.y] = 'P';
		win->map[begin.x][begin.y] = '0';
		win->map[begin.x+1][begin.y] = 'P';
		print_map_window(win->mlx, win->windows, win->map);

	}
	print_map(win->map);
	return (1);
}

int	main(int av, char **args)
{
	t_windows	windows;
	t_point	position;

	if (!error_handler(av, args))
		return (0);
	windows.mlx = mlx_init();
	windows.map = get_map(args[1]);
	position.y = ft_len_line(windows.map);
	position.x = (int) ft_strlen(*(windows.map));
	windows.windows = mlx_new_window(windows.mlx, position.x * 83, position.y * 56, "SO LONG");
	mlx_key_hook(windows.windows, keypress, &windows);
	//print_map(map);
	print_map_window(windows.mlx, windows.windows, windows.map);
	mlx_loop(windows.mlx);
	return (0);
}
