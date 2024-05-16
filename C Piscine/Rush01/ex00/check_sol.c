/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmarco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:31:44 by marmarco          #+#    #+#             */
/*   Updated: 2023/11/26 18:31:47 by marmarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_up(int size, int **sol, int col, int expected)
{
	int	i;
	int	pov;
	int	max;

	pov = 0;
	max = 0;
	i = 0;
	while (i < size)
	{
		if (max < sol[i][col])
		{			
			max = sol[i][col];
			++pov;
		}
		++i;
	}
	if (pov != expected)
		return (0);
	return (1);
}

int	check_down(int size, int **sol, int col, int expected)
{
	int	i;
	int	pov;
	int	max;

	pov = 0;
	max = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (max < sol[i][col])
		{			
			max = sol[i][col];
			++pov;
		}
		--i;
	}
	if (pov != expected)
		return (0);
	return (1);
}

int	check_left(int size, int **sol, int row, int expected)
{
	int	i;
	int	pov;
	int	max;

	pov = 0;
	max = 0;
	i = 0;
	while (i < size)
	{
		if (max < sol[row][i])
		{			
			max = sol[row][i];
			++pov;
		}
		++i;
	}
	if (pov != expected)
		return (0);
	return (1);
}

int	check_right(int size, int **sol, int row, int expected)
{
	int	i;
	int	pov;
	int	max;

	pov = 0;
	max = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (max < sol[row][i])
		{			
			max = sol[row][i];
			++pov;
		}
		--i;
	}
	if (pov != expected)
		return (0);
	return (1);
}

int	sol_correct(int size, int **sol, int **input)
{
	int	i;
	int	j;
	int	correct;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < size)
		{
			if (i == 0)
				correct = check_up(size, sol, j, input[i][j]);
			else if (i == 1)
				correct = check_down(size, sol, j, input[i][j]);
			else if (i == 2)
				correct = check_left(size, sol, j, input[i][j]);
			else
				correct = check_right(size, sol, j, input[i][j]);
			if (!correct)
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}
