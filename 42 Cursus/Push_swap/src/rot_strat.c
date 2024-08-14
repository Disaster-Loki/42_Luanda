/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_strategy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:34:52 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/11 13:34:54 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	use_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->content != c && find_place(*b, c) > 0)
			rr(a, b);
		while ((*a)->content != c)
			ra(a);
		while (find_place(*b, c) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->content != c && find_place(*a, c) > 0)
			rr(a, b);
		while ((*b)->content != c)
			rb(b);
		while (find_place(*a, c) > 0)
			ra(a);
		pa(a, b);
	}
	return (-1);
}

int	use_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->content != c && find_place(*b, c) > 0)
			rrr(a, b);
		while ((*a)->content != c)
			rra(a);
		while (find_place(*b, c) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->content != c && find_place(*a, c) > 0)
			rrr(a, b);
		while ((*b)->content != c)
			rrb(b);
		while (find_place(*a, c) > 0)
			rra(a);
		pa(a, b);
	}
	return (-1);
}

int	use_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->content != c)
			rra(a);
		while (find_place(*b, c) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while (find_place(*a, c) > 0)
			rra(a);
		while ((*b)->content != c)
			rb(b);
		pa(a, b);
	}
	return (-1);
}

int	use_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->content != c)
			ra(a);
		while (find_place(*b, c) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while (find_place(*a, c) > 0)
			ra(a);
		while ((*b)->content != c)
			rrb(b);
		pa(a, b);
	}
	return (-1);
}
