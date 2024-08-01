/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:15:28 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/01 15:15:30 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = ft_lst_last(*stack);
	tmp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next->prev = tmp;
	tmp->next->next = NULL;
}

void	ra(t_stack **stack)
{
	rotate(stack);
	ft_putstr("ra\n", LIME);
}

void	rb(t_stack **stack)
{
	rotate(stack);
	ft_putstr("rb\n", LIME);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n", LIME);
}
