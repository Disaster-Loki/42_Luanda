/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:48:25 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/04 11:48:27 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_three(t_stack **stack)
{
	while (check_sorted(stack) != 1)
	{
		if (((*stack)->index > (*stack)->next->index)
			&& ((*stack)->index < ((*stack)->next->next->index)))
			sa(stack);
		else if (((*stack)->index > ((*stack)->next->index))
			&& ((*stack)->index > (*stack)->next->next->index))
			ra(stack);
		else
			rra(stack);
	}
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	if (sorted_to_top(stack_a, 4) == 1)
		return ;
	move_min_to_top(stack_a, 4);
	pb(stack_a, stack_b);
	reset_index(stack_a);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = lst_size(*stack_a);
	if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else
	{
		if (sorted_to_top(stack_a, 5) == 1)
			return ;
		move_min_to_top(stack_a, 5);
		pb(stack_a, stack_b);
		reset_index(stack_a);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
