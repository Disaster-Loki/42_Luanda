/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:47:09 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/11 16:55:56 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int av, char **args)
{
	int	div = 2;
	int	num = 0;

	if (av == 2)
	{
		num = atoi(args[1]);
		if (num == 1)
			printf("1");
		while (div <= num)
		{
			if (num % div == 0)
			{
				printf("%d", div);
				num /= div;
				if (num > 1)
					printf("*");
				div = 1;
			}
			div++;
		}
	}
	printf("\n");
	return (0);
}
