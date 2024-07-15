/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:45:57 by sde-carv          #+#    #+#             */
/*   Updated: 2024/07/11 14:54:37 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct  s_point
{
   int           x;
   int           y;
}               t_point;

void	fill(char **tab, t_point size, t_point begin, char ch)
{
	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x || tab[begin.y][begin.x] != ch)
		return;
	tab[begin.y][begin.x] = 'F';
	fill(tab, size, (t_point){begin.x+1, begin.y}, ch);
	fill(tab, size, (t_point){begin.x-1, begin.y}, ch);
	fill(tab, size, (t_point){begin.x, begin.y+1}, ch);
	fill(tab, size, (t_point){begin.x, begin.y-1}, ch);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

