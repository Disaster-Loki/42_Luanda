/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:23:45 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/08 15:33:42 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int av, char **args)
{
	int	i = 0;
	if (av == 4)
	{
		int	n1 = atoi(args[1]);
		int	n2 = atoi(args[3]);
		if (args[2][0] == '+')
			printf("%d", (n1+n2));
		if (args[2][0] == '-')
                        printf("%d", (n1-n2));
		if (args[2][0] == '*')
                        printf("%d", (n1*n2));
		if (args[2][0] == '/')
                        printf("%d", (n1/n2));
		if (args[2][0] == '%')
                        printf("%d", (n1%n2));
	}
	printf("\n");
	return (0);
}
