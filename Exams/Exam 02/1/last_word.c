/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:58:12 by sde-carv          #+#    #+#             */
/*   Updated: 2024/06/26 15:27:20 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int av, char **args)
{
	int	i;
	char	*str;

	i = 0;
	str = args[1];
	if ( av == 2)
	{
		while (str[i])
			i++;
		i--;
		while (str[i] == ' ' || str[i] == '\t')
			i--;
		while (str[i] != ' ' && str[i] != '\t')
			i--;
		i++;
		while(str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
			ft_putchar(str[i++]);
	}
	ft_putchar ('\n');
	return (0);
}
