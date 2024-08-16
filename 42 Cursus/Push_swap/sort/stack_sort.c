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

void	sort_three(t_stack **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack)->content;
	mid = (*stack)->next->content;
	bot = (*stack)->next->next->content;
	if (top > mid && mid < bot && top < bot)
		sa(stack);
	else if (top > mid && mid > bot)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > bot && bot > mid)
		ra(stack);
	else if (mid > bot && bot > top)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < mid && mid > bot)
		rra(stack);
}

void	ft_partition_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (lst_size(*stack_a) > 3 && !check_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = min_rot_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb(*stack_a, *stack_b, tmp->content))
				i = use_rarb(stack_a, stack_b, tmp->content, 'a');
			else if (i == case_rrarrb(*stack_a, *stack_b, tmp->content))
				i = use_rrarrb(stack_a, stack_b, tmp->content, 'a');
			else if (i == case_rarrb(*stack_a, *stack_b, tmp->content))
				i = use_rarrb(stack_a, stack_b, tmp->content, 'a');
			else if (i == case_rrarb(*stack_a, *stack_b, tmp->content))
				i = use_rrarb(stack_a, stack_b, tmp->content, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*ft_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	if (lst_size(*stack_a) > 3 && !check_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (lst_size(*stack_a) > 3 && !check_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (lst_size(*stack_a) > 3 && !check_sorted(*stack_a))
		ft_partition_stack(stack_a, stack_b);
	if (!check_sorted(*stack_a))
		sort_three(stack_a);
	return (*stack_b);
}

t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = min_rot_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == case_rarb_a(*stack_a, *stack_b, tmp->content))
				i = use_rarb(stack_a, stack_b, tmp->content, 'b');
			else if (i == case_rarrb_a(*stack_a, *stack_b, tmp->content))
				i = use_rarrb(stack_a, stack_b, tmp->content, 'b');
			else if (i == case_rrarrb_a(*stack_a, *stack_b, tmp->content))
				i = use_rrarrb(stack_a, stack_b, tmp->content, 'b');
			else if (i == case_rrarb_a(*stack_a, *stack_b, tmp->content))
				i = use_rrarb(stack_a, stack_b, tmp->content, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void	quick_sorted(t_stack **stack_a, t_stack **stack_b)
{
	int		i;

	if (lst_size(*stack_a) == 2)
		sa(stack_a);
	else
	{
		*stack_b = ft_sort_b(stack_a, stack_b);
		stack_a = ft_sort_a(stack_a, stack_b);
		i = find_index(*stack_a, min(*stack_a));
		if (i < lst_size(*stack_a) - i)
		{
			while ((*stack_a)->content != min(*stack_a))
				ra(stack_a);
		}
		else
		{
			while ((*stack_a)->content != min(*stack_a))
				rra(stack_a);
		}
	}
}
