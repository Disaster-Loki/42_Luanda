/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_strat_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:51:17 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/11 13:51:21 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	min_rot_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = case_rrarrb_a(a, b, b->content);
	while (tmp)
	{
		if (i > case_rarb_a(a, b, tmp->content))
			i = case_rarb_a(a, b, tmp->content);
		if (i > case_rrarrb_a(a, b, tmp->content))
			i = case_rrarrb_a(a, b, tmp->content);
		if (i > case_rarrb_a(a, b, tmp->content))
			i = case_rarrb_a(a, b, tmp->content);
		if (i > case_rrarb_a(a, b, tmp->content))
			i = case_rrarb_a(a, b, tmp->content);
		tmp = tmp->next;
	}
	return (i);
}

int	min_rot_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = case_rrarrb(a, b, a->content);
	while (tmp)
	{
		if (i > case_rarb(a, b, tmp->content))
			i = case_rarb(a, b, tmp->content);
		if (i > case_rrarrb(a, b, tmp->content))
			i = case_rrarrb(a, b, tmp->content);
		if (i > case_rarrb(a, b, tmp->content))
			i = case_rarrb(a, b, tmp->content);
		if (i > case_rrarb(a, b, tmp->content))
			i = case_rrarb(a, b, tmp->content);
		tmp = tmp->next;
	}
	return (i);
}
