/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:53:17 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/06 14:56:39 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// print the copied map
void print_copied_map(t_config *config)
{
	size_t	i;
	size_t	height;

	i = 0;
	height = config->map_height;
	printf("Copied map:\n");
	while (i < height)
	{
		printf("%s\n", config->map_copy[i]);
		i++;
	}
}