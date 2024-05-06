/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:53:47 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/06 20:19:23 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Check if the map is a rectangle
 */
int is_map_rectangle(t_config *config)
{
	size_t	i;
	size_t	height;
	size_t	width;

	i = 0;
	height = config->map_height;
	width = config->map_width;
	while (i < height)
	{
		if (ft_strlen(config->map_copy[i]) != width)
			return (printf("Error: Map is not a rectangle\n"), 1);
		i++;
	}
	return (0);
}

/**
 * Check top and bottom of map have only '1' and ' '
 */
int check_top_bottom(t_config *config)
{
	size_t	i;
	size_t	height = config->map_height;
	size_t	width = config->map_width;

	i = 0;
	while (i < width)
	{
		if (config->map_copy[0][i] != '1' && config->map_copy[0][i] != ' ')
			return (printf("Error: Map is not surrounded by walls\n"), 1);
		if (config->map_copy[height - 1][i] != '1'
			&& config->map_copy[height - 1][i] != ' ')
			return (printf("Error: Map is not surrounded by walls\n"), 1);
		i++;
	}
	return (0);
}

/**
 * Check left and right of map have only '1' and ' '
 */
int check_left_right(t_config *config)
{
	size_t	i;
	size_t	height;
	size_t	width;

	i = 0;
	height = config->map_height;
	width = config->map_width;
	while (i < height)
	{
		if (config->map_copy[i][0] != '1' && config->map_copy[i][0] != ' ')
			return (printf("Error: Map is not surrounded by walls\n"), 1);
		if (config->map_copy[i][width - 1] != '1'
			&& config->map_copy[i][width - 1] != ' ')
			return (printf("Error: Map is not surrounded by walls\n"), 1);
		i++;
	}
	return (0);
}