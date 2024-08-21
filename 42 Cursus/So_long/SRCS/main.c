#include "../inc/so_long.h"

int main(int av, char **args)
{
    if(!error_handler(av, args))
        return (0);
    ft_putstr_fd("Success reading the file\n", 1);
    return (0);
}