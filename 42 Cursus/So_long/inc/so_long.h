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

// Error handler
void	error(char *msg, int n);
char	*valid_read_file(int fd);
int		main(int av, char **args);
int		valid_open_file(char *file);
int		error_handler(int av, char **args);
// Error utils
int		check_character(char c);
// Validate String
void	validate_string(char *str);
// Validate Maps
int	    validate_maps(char **map);
void	valid_character(char **map);
void	valid_walls_map(char **map, char c);

#endif
