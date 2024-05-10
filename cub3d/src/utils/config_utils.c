/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:11:20 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/10 11:46:55 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_config(t_config *config, int *line_number)
{
	config->no_texture = NULL;
	config->we_texture = NULL;
	config->so_texture = NULL;
	config->ea_texture = NULL;
	config->floor_color = -1;
	config->ceiling_color = -1;
	config->map_copy = NULL;
	config->map = NULL;
	config->map_height = 0;
	config->map_width = 0;
	*line_number = 1;
}

void	free_texture(char **texture)
{
	if (*texture)
	{
		free(*texture);
		*texture = NULL;
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
		if (config->map[i])
			free(config->map[i]);
		i++;
	}
	free(config->map);
	config->map = NULL;
}

void	free_copy_map(t_config *config)
{
	size_t	i;
	size_t	height;

	i = 0;
	height = config->map_height;
	while (i < height)
	{
		if (config->map_copy[i])
			free(config->map_copy[i]);
		i++;
	}
	free(config->map_copy);
	config->map_copy = NULL;
}

void	free_config(t_config *config)
{
	free_texture(&config->no_texture);
	free_texture(&config->we_texture);
	free_texture(&config->so_texture);
	free_texture(&config->ea_texture);
	if (config->map_copy)
		free_copy_map(config);
	if (config->map)
		free_map(config);
	free(config);
}
