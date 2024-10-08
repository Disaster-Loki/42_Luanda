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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!error_handler(argc, argv))
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	init_stack(argc, argv, &stack_a);
	get_index(&stack_a);
	if (!check_sorted(stack_a))
		quick_sorted(&stack_a, &stack_b);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	return (0);
}
