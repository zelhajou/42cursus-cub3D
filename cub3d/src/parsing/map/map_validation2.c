/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:19:21 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/08 17:56:08 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space_within_map_bounds(size_t i, size_t j, t_config *config,
		char **map_copy)
{
	size_t	height;
	size_t	width;

	height = config->map_height;
	width = config->map_width;
	if (i > 0 && map_copy[i - 1][j] != '1'
		&& map_copy[i - 1][j] != ' ')
		return (1);
	if (i < height - 1 && map_copy[i + 1][j] != '1'
		&& map_copy[i + 1][j] != ' ')
		return (1);
	if (j > 0 && map_copy[i][j - 1] != '1'
		&& map_copy[i][j - 1] != ' ')
		return (1);
	if (j < width - 1 && map_copy[i][j + 1] != '1'
		&& map_copy[i][j + 1] != ' ')
		return (1);
	return (0);
}

int	check_empty_space(t_config *config)
{
	size_t	i;
	size_t	j;
	size_t	height;
	size_t	width;

	i = 0;
	j = 0;
	height = config->map_height;
	width = config->map_width;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (config->map_copy[i][j] == ' ')
			{
				if (is_space_within_map_bounds(i, j, config, config->map_copy))
					return (printf("Error: Map is not closed\n"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

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
