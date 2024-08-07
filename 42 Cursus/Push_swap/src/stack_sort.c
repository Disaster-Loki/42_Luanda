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

static void	rotate_to_min(t_stack **stack, int min_pos, int stack_size)
{
	if (min_pos <= stack_size / 2)
	{
		while (min_pos-- > 0)
			ra(stack);
	}
	else
	{
		min_pos = stack_size - min_pos;
		while (min_pos-- > 0)
			rra(stack);
	}
}

static void	sort_three(t_stack **stack)
{
	int	top;
	int	mid;
	int	bot;

	while (!check_sorted(stack))
	{
		top = (*stack)->index;
		mid = (*stack)->next->index;
		bot = (*stack)->next->next->index;
		if (top > mid && top < bot)
			sa(stack);
		else if (top > mid && top > bot)
			ra(stack);
		else
			rra(stack);
	}
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;

	if (check_sorted(stack_a))
		return ;
	min_pos = find_min_pos(stack_a);
	rotate_to_min(stack_a, min_pos, lst_size(*stack_a));
	if (!check_sorted(stack_a))
	{
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;

	if (check_sorted(stack_a))
		return ;
	min_pos = find_min_pos(stack_a);
	rotate_to_min(stack_a, min_pos, lst_size(*stack_a));
	if (!check_sorted(stack_a))
	{
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = lst_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
