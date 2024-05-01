/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_line_handlers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:44:02 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/01 19:50:34 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_texture_line(char *line, t_config *config, int *map_started)
{
	if (config->no_texture && config->we_texture
		&& config->so_texture && config->ea_texture)
		return (printf("Error: Textures already set\n"), 1);
	if (config->floor_color || config->ceiling_color || *map_started)
	{
		printf("Error: Texture must be defined before colors or map\n");
		return (1);
	}
	if (parse_texture_type(line, config))
		return (1);
	return (0);
}

int	handle_color_line(char *line, t_config *config)
{
	if (config->floor_color && config->ceiling_color)
		return (printf("Error: Colors already set\n"), 1);
	if (!config->no_texture || !config->we_texture
		|| !config->so_texture || !config->ea_texture)
	{
		printf("Error: Colors must be defined after defining all textures\n");
		return (1);
	}
	if (parse_color_type(line, config))
		return (1);
	return (0);
}

int	handle_map_line(char *line, t_config *config, int *map_started)
{
	if (!config->no_texture || !config->we_texture
		|| !config->so_texture || !config->ea_texture
		|| !config->floor_color || !config->ceiling_color)
	{
		printf("Error: Map must be defined after definig all textures and colors first\n");
		return (1);
	}
	*map_started = 1;
	printf("Map: %s\n", line);
	// Parse map
	return (0);
}
