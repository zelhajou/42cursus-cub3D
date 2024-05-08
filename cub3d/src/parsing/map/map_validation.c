/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:53:47 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/08 17:56:36 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
