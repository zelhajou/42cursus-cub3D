/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_line_handlers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:44:02 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/04 01:56:51 by beddinao         ###   ########.fr       */
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

int handle_map_line(char *line, t_config *config, int *map_started)
{
    size_t line_width;

    if (!config->no_texture || !config->we_texture || !config->so_texture
        || !config->ea_texture || !config->floor_color || !config->ceiling_color)
	{
        printf("Error: Map must be defined after defining all textures and colors first\n");
        return 1;
    }
    *map_started = 1;
    line_width = strlen(line);
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
        config->map = realloc(config->map, sizeof(char*) * config->map_height);
    }
    config->map[config->map_height - 1] = malloc((line_width + 1) * sizeof(char));
    ft_strlcpy(config->map[config->map_height - 1], line, line_width + 1);
    return (0);
}
