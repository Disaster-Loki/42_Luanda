/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:01:39 by sde-carv          #+#    #+#             */
/*   Updated: 2024/05/18 12:07:41 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int u)
{
	if (u >= 'a' && u <= 'z')
		u -= 32;
	return (u);
}