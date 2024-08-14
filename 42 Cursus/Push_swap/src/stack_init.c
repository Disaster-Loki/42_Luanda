/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:08:56 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/04 13:08:59 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	init_stack(int av, char **args, t_stack **stack_a)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (++i < av)
	{
		j = -1;
		split = ft_split(args[i], ' ');
		while (split[++j])
			ft_lst_addback(stack_a, ft_lst_new(ft_atoi(split[j])));
		free_split(split);
	}
	return (1);
}

void	clear_stack(t_stack **stack)
{
	t_stack	*current;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
	*stack = NULL;
}
