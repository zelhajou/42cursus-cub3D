/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:20:39 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/08 19:43:19 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	ft_atoi() convert a string to an integer
*/

#include "libft.h"

void	handle_color_error(int key)
{
	if (key == 1)
	{
		printf("Error: Color out of range\n");
		exit(1);
	}
	else
		exit(0);
}

int	ft_atoi(const char *s)
{
	int	sign;
	int	nb;
	int	n;

	nb = 0;
	sign = 1;
	if (*s == '+')
		s++;
	if (*s == '-' && s++)
		sign = -1;
	while (*s)
	{
		n = (*s - 48) * sign;
		if (nb > (INT_MAX / 10) || (nb == (INT_MAX / 10) && n > 7))
			handle_color_error(1);
		if (nb < (INT_MIN / 10) || (nb == (INT_MIN / 10) && n < -8))
			handle_color_error(1);
		nb = nb * 10 + n;
		s++;
	}
	return (nb);
}
