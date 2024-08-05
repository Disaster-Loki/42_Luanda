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

int	check_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*int	sorted_to_top(t_stack **stack, int size)
{
	int	i;

	i = 0;
	while ((*stack)->index != 0)
	{
		rotate(stack);
		i++;
	}
	if (check_sorted(stack) == 1)
	{
		if (i > (size / 2))
		{
			if ((size == 5) && (i == 3))
				ft_putstr("rra\n", BLUE);
			ft_putstr("rra\n", BLUE);
		}
		else
			while (i-- > 0)
				ft_putstr("ra\n", LIME);
		return (1);
	}
	else
		while (i-- > 0)
			reverse(stack);
	return (0);
}*/

void	reset_index(t_stack **stack)
{
	t_stack	*lst;

	lst = *stack;
	while (lst)
	{
		lst->index = -1;
		lst = lst->next;
	}
	get_index(stack);
}

int	find_min_pos(t_stack **stack)
{
	int		i;
	int		min;
	int		pos;
	t_stack	*tmp;

	tmp = *stack;
	min = tmp->index;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index < min)
		{
			min = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	move_min_to_top(t_stack **stack, int size)
{
	int	i;
	int	pos;

	pos = find_min_pos(stack);
	i = pos;
	if (i > size / 2)
		i = size - i;
	while (i-- > 0)
	{
		if (pos > size / 2)
			reverse(stack);
		else
			rotate(stack);
	}
}
