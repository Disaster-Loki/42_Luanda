/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 10:47:17 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/04 10:47:19 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_sorted(t_stack *stack)
{
	int	i;

	i = stack->content;
	while (stack)
	{
		if (i > stack->content)
			return (0);
		i = stack->content;
		stack = stack->next;
	}
	return (1);
}

int	find_index(t_stack *stack, int content)
{
	int	i;

	i = 0;
	while (stack->content != content)
	{
		i++;
		stack = stack->next;
	}
	stack->index = 0;
	return (i);
}

int	find_place_b(t_stack *stack_b, int content)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (content > stack_b->content && content < ft_lst_last(stack_b)->content)
		i = 0;
	else if (content > max(stack_b) || content < min(stack_b))
		i = find_index(stack_b, max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->content < content || tmp->content > content)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	find_place_a(t_stack *stack_a, int content)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (content < stack_a->content && content > ft_lst_last(stack_a)->content)
		i = 0;
	else if (content > max(stack_a) || content < min(stack_a))
		i = find_index(stack_a, min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->content > content || tmp->content < content)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}

