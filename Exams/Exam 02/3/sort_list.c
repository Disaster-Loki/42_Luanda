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

#include <stdlib.h>

typedef struct s_list t_list;

struct s_list {
    int data;
    t_list *next;
};

t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
    int tmp = 0;
    int sorted = 0;
    t_list  *begin = lst;
    t_list  *current;
    if (!lst)
        return (NULL);
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
    return (begin);
}

