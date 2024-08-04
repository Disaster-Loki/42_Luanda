/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:08:14 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/04 11:08:17 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_stack	*get_min(t_stack **stack)
{
	int		min;
	t_stack	*lst;
	t_stack	*lst_min;

	if (!(*stack))
		return (NULL);
	min = 0;
	lst = *stack;
	lst_min = NULL;
	while (lst)
	{
		if ((lst->index == -1)
			&& (!min || (lst->content < lst_min->content)))
		{
			lst_min = lst;
			min = 1;
		}
		lst = lst->next;
	}
	return (lst_min);
}

void	get_index(t_stack **stack)
{
	int		index;
	t_stack	*lst;

	index = 0;
	lst = get_min(stack);
	while (lst)
	{
		lst->index = index++;
		lst = get_min(stack);
	}
}
