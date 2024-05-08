/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:11:20 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/08 15:43:07 by zelhajou         ###   ########.fr       */
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
		free(config->map[i]);
		i++;
	}
	free(config->map);
	config->map = NULL;
}


void	free_config(t_config *config)
{
	free_texture(&config->no_texture);
	free_texture(&config->we_texture);
	free_texture(&config->so_texture);
	free_texture(&config->ea_texture);
	free_map(config);
	free(config);
}

void	display_config(t_config *config)
{
	size_t	i;

	i = 0;
	printf("NO texture: %s\n", config->no_texture);
	printf("WE texture: %s\n", config->we_texture);
	printf("SO texture: %s\n", config->so_texture);
	printf("EA texture: %s\n", config->ea_texture);
	printf("Floor color: %d\n", config->floor_color);
	printf("Ceiling color: %d\n", config->ceiling_color);
	printf("Map:\n");
	while (i < config->map_height)
	{
		printf("%s\n", config->map[i]);
		i++;
	}
	printf("config->map_height: %zu\n", config->map_height);
	printf("config->map_width: %zu\n", config->map_width);
	i = 0;
	printf("Map copy:\n");
	while (i < config->map_height)
	{
		printf("%s\n", config->map_copy[i]);
		i++;
	}
}
