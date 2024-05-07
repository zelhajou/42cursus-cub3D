/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:14:42 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/07 17:16:19 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_map_line(char *line, t_config *config, int *map_started)
{
	size_t	line_width;

	if (!config->no_texture || !config->we_texture || !config->so_texture
		|| !config->ea_texture || !config->floor_color
		|| !config->ceiling_color)
		return (printf("Error: Map must be defined in the end\n"), 1);
	*map_started = 1;
	line_width = ft_strlen(line);
	if (config->map_height == 0 || config->map == NULL)
	{
		config->map_height = 1;
		config->map = malloc(sizeof(char*));
		config->map_width = line_width;
	}
	else
	{
		if (line_width > config->map_width)
			config->map_width = line_width;
		config->map_height++;
		config->map = ft_realloc(config->map, sizeof(char *) * config->map_height);
	}
	config->map[config->map_height - 1] = malloc((line_width + 1) * sizeof(char));
	ft_strlcpy(config->map[config->map_height - 1], line, line_width + 1);
	return (0);
}

int	is_valid_map(t_config *config)
{
	if (fill_map_with_spaces(config))
		return (1);
	if (is_map_rectangle(config))
		return (1);
	if (check_top_bottom(config) || check_left_right(config))
		return (1);
	if (check_empty_space(config))
		return (1);
	if (is_valid_map_char(config))
		return (1);
	if (is_player_position_valid(config))
		return (1);
	free_map(config);
	config->map = config->map_copy;
	return (0);
}

int	fill_map_with_spaces(t_config *config)
{
	size_t	i;
	size_t	width;

	i = 0;
	width = config->map_width;
	config->map_copy = malloc(config->map_height * sizeof(char *));
	if (!config->map_copy)
		return (1);
	while (i < config->map_height)
	{
		config->map_copy[i] = malloc(width + 1);
		if (!config->map_copy[i])
			return (1);
		ft_memset(config->map_copy[i], ' ', width);
		config->map_copy[i][width] = '\0';
		i++;
	}
	i = 0;
	while (i < config->map_height)
	{
		ft_strncpy(config->map_copy[i], config->map[i],
			ft_strlen(config->map[i]));
		i++;
	}
	return (0);
}

/**
 * Check when found an empty space in the map, must be surrounded by 1 or ' '
*/
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
				if (i > 0 && config->map_copy[i - 1][j] != '1'
					&& config->map_copy[i - 1][j] != ' ')
					return (printf("Error: Map is not surrounded by walls\n"), 1);
				if (i < height - 1 && config->map_copy[i + 1][j] != '1'
					 && config->map_copy[i + 1][j] != ' ')
					return (printf("Error: Map is not surrounded by walls\n"), 1);
				if (j > 0 && config->map_copy[i][j - 1] != '1'
					&& config->map_copy[i][j - 1] != ' ')
					return (printf("Error: Map is not surrounded by walls\n"), 1);
				if (j < width - 1 && config->map_copy[i][j + 1] != '1'
					&& config->map_copy[i][j + 1] != ' ')
					return (printf("Error: Map is not surrounded by walls\n"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
