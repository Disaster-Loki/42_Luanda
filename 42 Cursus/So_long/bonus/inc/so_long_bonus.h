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

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../libft/inc/libft.h"
# include "../../minilibx-linux/mlx.h"

# define ESC 65307

typedef struct s_point
{
	int		x;
	int		y;
	char	ch;
	int		count;
	char	exit;
	char	enemy;
}			t_point;

typedef struct s_img
{
	void	*player[8];
	void	*enemy[4];
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
	int		move;
	int		frame;
	int		count;
	char	**map;
	int		t_move;
	char	*g_name;
	int		v_tible;
	int		c_tibles;
	int		t_tibles;
	int		frame_count;
	int		**move_tibles;
}			t_game;

void	window_init(char **args);
void	print_steps(t_game *game);
void	print_t_tibles(t_game *game);
void	print_map_window(t_game *game);
void	get_init(t_game *game, char **args);
void	print_image_player(t_game *g, int w, int h);
void	get_img_path(t_game *game, char *mlx, t_img *img);
void	print_image(t_game *game, char c, int wid, int hei);
void	get_img_path_enemy(char *mlx, t_img *img, int x, int y);
void	get_img_path_player(char *mlx, t_img *img, int x, int y);

int		close_game(t_game *game);
int		window_stop(t_game *game);
int		window_close(t_game *game);
void	game_over(t_game *game, char c);
void	close_img(void *mlx, t_img *img);

void	get_count_exit(t_game *game);
void	get_count_steps(t_game *game);
int		keypress(int key, t_game *game);
void	get_player_animation(t_game *game, int x, int y);
void	get_alter_position(t_game *game, t_point begin, int x, int y);

char	**get_map(char *str);
int		ft_len_line(char **map);
char	*read_map_content(int fd);

void	error(char *msg);
void	free_map(char **map);
char	**dup_map(char **map);
int		check_character(char c);
int		validate_maps(char **map);
void	valid_read_file(int size);
void	validate_string(char *str);
void	valid_character(char **map);
int		valid_open_file(char *file);
int		total_collectable(char **map);
void	error_str(char *msg, char *str);
void	error_map(char *msg, char **map);
t_point	begin_position(char **map, char c);
int		error_handler(int av, char **args);
void	free_matrix(int **matrix, int rows);
int		single_character(char *map, char c);
void	valid_walls_map(char **map, char c);
void	validate_single_character(char *str);
void	valid_img_path(t_game *game, t_img *img);
void	valid_path_map(char **map, int c, char s, char e);
void	walk_path(char **map, int x, int y, t_point *begin);
void	valid_path_map_exit(char **map, char **copy, char s, char e);

void	get_move_enimy(t_game *game);
int		manipulate_enemies(t_game *game);
void	get_alter_direction(t_game *game);
void	move_enemy(t_game *game, int line);
int		is_valid_move(int new_x, int t_col, char c);
void	move_enemy_tibles(t_game *game, int line, int col, int new_x);
void	move_enemy_to_empty(t_game *game, int line, int col, int new_x);
void	handle_enemy_collision(t_game *game, int line, int col, int new_x);

#endif
