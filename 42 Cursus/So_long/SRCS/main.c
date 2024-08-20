#include "../inc/so_long.h"

int main(int av, char **args)
{
    (void)av;
    valid_open_file(args[1]);
    ft_putstr_fd("Success reading the file\n", 1);
    return (0);
}