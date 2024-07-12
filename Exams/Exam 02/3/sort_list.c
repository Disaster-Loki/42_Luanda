/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:12:44 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/12 12:12:46 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int tmp;
    t_list *begin = lst;
    t_list *current;

    if (!lst)
        return NULL;

    int sorted = 0;

    while (!sorted)
    {
        sorted = 1;
        current = begin;

        while (current->next)
        {
            if (!cmp(current->data, current->next->data))
            {
                tmp = current->data;
                current->data = current->next->data;
                current->next->data = tmp;
                sorted = 0;
            }
            current = current->next;
        }
    }

    return begin;
}


