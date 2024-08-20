#include "../../inc/so_long.h"

void	error(char *msg, int n)
{
	ft_putstr_fd(msg, 1);
	exit(n);
}

int	valid_open_file(char *file)
{
	int		i;
	int		fd;
	int		len;
	char	*ext;

	i = 0;
	ext = "ber";
	len = (int) ft_strlen(file) - 3;
	while (file[len++] == ext[i])
		i++;
	if (i != 4)
		error("Error - extension invalid !!\n", 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Error openning the file !!\n", 1);
	return (fd);
}

char	valid_read_file(char *buffer, int fd)
{
	int	size;

	size = 0;
	buffer = (char *)malloc(sizeof(char) * 1024);
	if (!buffer)
		return (0);
	size = read(fd, buffer, 1024);
	if (size == -1)
	{
		close(fd);
		free(buffer);
		error("Error reading the file !!\n", 1);
	}
	buffer[size] = '\0';
	return (buffer);
}

int error_handler(char *args)
{
	int		i;
	int		j;
	int		fd;
	char	*buffer;
	char	**map;

	fd = valid_open_file(args);
	map = ft_split(valid_read_file(buffer, fd), '\n');
	 i = -1;
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
            printf("%c", map[i][j]);
        printf("\n");
    }
	 i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
    free(buffer);
    close(fd);
	return (1);
}