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

#include "../../inc/so_long.h"

void	error(char *msg)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	exit(1);
}

void	error_str(char *msg, char *str)
{
	free(str);
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	exit(1);
}

void	error_map(char *msg, char **map)
{
	ft_free(map);
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	exit(1);
}

int	valid_open_file(char *file)
{
	int		fd;
	int		len;
	char	*ext;

	ext = ".ber";
	len = (int) ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ext, 4) != 0)
		error("Error - Invalid extension !!\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Error - Openning the file !!\n");
	return (fd);
}

int	error_handler(int av, char **args)
{
	char	**map;

	if (av < 2)
		error("Error - Missing arguments\n");
	map = get_map(args[1]);
	validate_maps(map);
	ft_free(map);
	return (1);
}
