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

int	min(t_stack *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	max(t_stack *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

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

int find_index(t_stack *a, int content)
{
    int i;

    i = 0;
    while (a->content != content)
    {
        i++;
        a = a->next;
    }
    a->index = 0;
    return (i);
}

int find_place(t_stack *stack_a, int content)
{
    int     i;
    t_stack *tmp;

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
