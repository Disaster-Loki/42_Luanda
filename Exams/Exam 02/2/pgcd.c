/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:43:09 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/13 14:43:12 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int av, char **args)
{
	int	i = 1;
	int	n, n2, min;
	int	count = 0;

	if (av == 3)
	{
		n = atoi(args[1]);
		n2 = atoi(args[2]);
		while ((i <= n) || (i <= n2))
		{
			if ((n % i == 0) && (n2 % i == 0))
				count = i;
			i++;
		}
		printf("%d", count);
	}
	printf("\n");
	return (0);
}

