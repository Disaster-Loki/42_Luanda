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

void	error(char *msg, int n)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	exit(n);
}

int	valid_open_file(char *file)
{
	int		fd;
	int		len;
	char	*ext;

	ext = ".ber";
	len = (int) ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ext, 4) != 0)
		error("Error - Invalid extension !!\n", 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Error - Openning the file !!\n", 1);
	return (fd);
}

void	valid_read_file(int fd)
{
	int		size;
	char	buffer[1024];

	size = read(fd, buffer, 1024);
	if (size == -1)
	{
		close(fd);
		error("Error - Reading the file !!\n", 1);
	}
	if (size == 0)
		error("Error - Map empty !!\n", 1);
	close(fd);
}

int	error_handler(int av, char **args)
{
	char	**map;

	if (av < 2)
		error("Error - Missing arguments\n", 1);
	map = get_map(args[1]);
	validate_maps(map);
	print_map(map);
	ft_free(map);
	return (1);
}
