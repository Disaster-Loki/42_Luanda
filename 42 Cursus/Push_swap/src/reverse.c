/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:15:40 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/01 15:15:42 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = ft_lst_last(*stack);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->prev;
}

void	rra(t_stack **stack)
{
	reverse(stack);
	ft_putstr("rra\n");
}

void	rrb(t_stack **stack)
{
	reverse(stack);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	ft_putstr("rrr\n");
}
