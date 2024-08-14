/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:50:27 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/11 12:50:29 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	case_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_place(a, c);
	if (i < find_index(b, c))
		i = find_index(b, c);
	return (i);
}

int	case_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place(a, c))
		i = lst_size(a) - find_place(a, c);
	if ((i < (lst_size(b) - find_index(b, c))) && find_index(b, c))
		i = lst_size(b) - find_index(b, c);
	return (i);
}

int	case_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_index(b, c))
		i = lst_size(b) - find_index(b, c);
	i = find_place(a, c) + i;
	return (i);
}

int	case_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place(a, c))
		i = lst_size(a) - find_place(a, c);
	i = find_index(b, c) + i;
	return (i);
}
