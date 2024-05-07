/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:53:47 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/07 17:22:10 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_rectangle(t_config *config)
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
int	check_top_bottom(t_config *config)
{
	size_t	i;
	size_t	height;
	size_t	width;

	i = 0;
	height = config->map_height;
	width = config->map_width;
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
int	check_left_right(t_config *config)
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

/**
 * Check if any character is not '1', '0', 'N', 'S', 'W', 'E' or ' '
*/
int	is_valid_map_char(t_config *config)
{
	size_t	i;
	size_t	j;
	char	**map;

	i = 0;
	j = 0;
	map = config->map_copy;
	while (i < config->map_height)
	{
		j = 0;
		while (j < config->map_width)
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != ' ')
			{
				printf("Error: Invalid character in the map\n");
				printf("Character found: %c\n", map[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * Check is the player position is valid
 */
int	is_player_position_valid(t_config *config)
{
	size_t	i;
	size_t	j;
	int		player_found;

	i = 0;
	j = 0;
	player_found = 0;
	while (i < config->map_height)
	{
		j = 0;
		while (j < config->map_width)
		{
			if (ft_strchr("NSWE", config->map_copy[i][j]))
			{
				if (player_found)
					return (printf("Error: Multiple player found\n"), 1);
				player_found = 1;
			}
			j++;
		}
		i++;
	}
	if (!player_found)
		return (printf("Error: No player position found\n"), 1);
	return (0);
}
