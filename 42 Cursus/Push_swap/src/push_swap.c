/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:09:22 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/31 16:09:24 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int av, char **args)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	error_handler(av, args);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(av, args, &stack_a);
	get_index(&stack_a);
	if (check_sorted(&stack_a) != 1)
	{
		if (lst_size(stack_a) <= 5)
			simple_sort(&stack_a, &stack_b);
		else
			radix_sort(&stack_a, &stack_b);
	}
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	return (0);
}
