/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:53:17 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/07 17:17:32 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_copied_map(t_config *config)
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

void	free_map(t_config *config)
{
	size_t	i;
	size_t	height;

	i = 0;
	height = config->map_height;
	while (i < height)
	{
		free(config->map[i]);
		i++;
	}
	free(config->map);
	config->map = NULL;
}
