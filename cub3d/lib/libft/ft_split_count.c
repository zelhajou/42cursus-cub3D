/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:22:29 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/26 16:07:32 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Count the number of elements in the split array
 * 
 * @param split array to count
 * @return int number of elements
 */
int	ft_split_count(char **split)
{
	int	count;

	if (!split)
		return (0);
	count = 0;
	while (split[count])
		count++;
	return (count);
}
