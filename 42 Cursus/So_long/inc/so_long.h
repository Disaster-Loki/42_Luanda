/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:47:53 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/20 09:48:06 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"

# define esc 65307

typedef struct s_point
{
	int		x;
	int		y;
	char	ch;
	int		count;
	char	exit;
}			t_point;

typedef struct s_img
{
	void	*player[4];
	void	*coin;
	void	*exit;
	void	*path;
	void	*wall;
	int		wid;
	int		hei;
}			t_img;

typedef struct s_game
{
	t_point	pos;
	t_img	img;
	void	*mlx;
	void	*win;
	int		flag;
	int		count;
	char	**map;
	char	*g_name;
	int		c_tibles;
	int		t_tibles;
}			t_game;

char	**dup_map(char **map);
int		main(int av, char **args);
void	error(char *msg);
int		len_str(char *str);
void	ft_free(char **map);
char	**get_map(char *str);
int		check_character(char c);
int		ft_len_line(char **map);
void	window_init(char **args);
int		close_game(t_game *game);
void	valid_read_file(int size);
char	*read_map_content(int fd);
int		validate_maps(char **map);
int		window_close(t_game *game);
void	validate_string(char *str);
void	valid_character(char **map);
int		valid_open_file(char *file);
void	get_count_exit(t_game *game);
int		total_collectable(char **map);
void	get_count_steps(t_game *game);
void	print_map_window(t_game *game);
void	error_str(char *msg, char *str);
int		keypress(int key, t_game *game);
void	error_map(char *msg, char **map);
void	close_img(void *mlx, t_img *img);
t_point	begin_position(char **map, char c);
int		error_handler(int av, char **args);
void	valid_walls_map(char **map, char c);
int		single_character(char *map, char c);
void	get_img_path(char *mlx, t_img *img);
void	get_init(t_game *game, char **args);
void	validate_single_character(char *str);
void	valid_path_map(char **map, int c, char s, char e);
void	walk_path(char **map, int x, int y, t_point *begin);
void	print_image(t_game *game, char c, int wid, int hei);
void	valid_path_map_exit(char **map, char **copy, char s, char e);
void	get_alter_position(t_game *game, t_point begin, int x, int y);

#endif
