/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:11:53 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/29 16:11:55 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	int tmp = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}