/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:14:30 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/01 15:14:33 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap(t_stack **stack)
{
	int	index;
	int	content;

	if (!(*stack)->next)
		return ;
	content = (*stack)->next->content;
	index = (*stack)->next->index;
	(*stack)->next->content = (*stack)->content;
	(*stack)->next->index = (*stack)->index;
	(*stack)->content = content;
	(*stack)->index = index;
}

void	sa(t_stack **stack)
{
	swap(stack);
	ft_putstr("sa\n");
}

void	sb(t_stack **stack)
{
	swap(stack);
	ft_putstr("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}
