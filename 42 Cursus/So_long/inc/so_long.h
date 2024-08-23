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

typedef struct s_point
{
    int     x;
    int     y;
    char    ch;
    int     found;
}   t_point;

// Error handler
void	error(char *msg, int n);
char	*valid_read_file(int fd);
int		main(int av, char **args);
int		valid_open_file(char *file);
int		error_handler(int av, char **args);
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
void	print_map(char **map);

#endif
