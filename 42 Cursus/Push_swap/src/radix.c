/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:22:46 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/04 12:22:48 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	calculate_max_bits(t_stack **stack)
{
	int		max;
	int		max_bits;
	t_stack	*lst;

	lst = *stack;
	max = lst->index;
	max_bits = 0;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;
	t_stack	*lst;

	i = -1;
	lst = *stack_a;
	size = lst_size(*stack_a);
	max_bits = calculate_max_bits(stack_a);
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			lst = *stack_a;
			if (((lst->index >> 1) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (lst_size(*stack_b) != 0)
			pa(stack_a, stack_b);
	}
}
