/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:48:45 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/29 16:48:47 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == 0 || *begin_list == 0)
		return ;
	t_list	*current = *begin_list;
	if (!(cmp(current->data, data_ref)))
	{
		*begin_list = current->next;
		free(current);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		current = *begin_list;
		ft_list_remove_if(&current->next, data_ref, cmp);
	}
}