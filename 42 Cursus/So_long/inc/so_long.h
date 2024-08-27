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
# include <stdio.h>
# include <fcntl.h>
# include "../Libft/inc/libft.h"
# include "../Minilibx/mlx.h"

# define BUFFER_SIZE 42

typedef struct s_point
{
    int     x;
    int     y;
    char    ch;
    int     count;
}   		t_point;

typedef struct s_img
{
	void	*player[2];
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
	t_img 	img;
	void	*mlx;
	void	*win;
	int 	flag;
	char	**map;
	int		count;
	char	*g_name;
	int		c_tibles;
	int		t_tibles;
}			t_game;

// Error handler
void	error(char *msg, int n);
int		main(int av, char **args);
int		valid_open_file(char *file);
int		error_handler(int av, char **args);
void	valid_read_file(int fd);
// Validate Utils
int		check_character(char c);
int     ft_len_line(char **map);
t_point	begin_position(char **map, char c);
int	    single_character(char *map, char c);
void	walk_path(char **map, int x, int y, t_point *begin);
// Validate String
void	validate_string(char *str);
void	validate_single_character(char *str);
// Validate Maps
int	    validate_maps(char **map);
void	valid_path_map(char **map);
void	valid_character(char **map);
void	valid_walls_map(char **map, char c);
void	valid_path(char **map, int c, char s);
// Validate Rest
char    **dup_map(char **map);
int     total_collectable(char **map);
// Free
void	ft_free(char **map);
// Get Maps
char	**get_map(char *str);
void	print_map(char **map);
char	*read_map_content(int fd);
// Get_Next_Line
char	*get_next_line(int fd);
char	*get_line(char *f_line);
char	*get_rest(char *f_line);
char	*read_line(int fd, char *str);
// Window Init
void	window_init(char **args);
void	print_map_window(t_game *game);
void	get_img_path(char *mlx, t_img *img);
void	print_image(t_game *game, char c, int wid, int hei);
// Keyboard
void	get_count_steps(t_game *game);
int		keypress(int key, t_game *game);
void	get_alter_position(t_game *game, t_point begin, int x, int y);
// Window close
int		close_game(t_game *game);
int		window_close(t_game *game);
void	close_img(void *mlx, t_img *img);

#endif
