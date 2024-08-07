/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:14:47 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/01 15:14:49 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b)
		return ;
	tmp = (*b)->next;
	ft_lst_addfront(a, *b);
	*b = tmp;
	if (*b)
		(*b)->prev = NULL;
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr("pb\n");
}
