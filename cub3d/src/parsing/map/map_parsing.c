/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:14:42 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/08 17:57:40 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_textures_and_colors_defined(t_config *config)
{
	if (!config->no_texture || !config->we_texture || !config->so_texture
		|| !config->ea_texture || config->floor_color == -1
		|| config->ceiling_color == -1)
	{
		printf("Error: Map must be defined ");
		printf("after defining all textures and colors\n");
		return (1);
	}
	return (0);
}

int	handle_map_line(char *line, t_config *config, int *map_started)
{
	size_t	line_width;

	if (check_textures_and_colors_defined(config))
		return (1);
	*map_started = 1;
	line_width = ft_strlen(line);
	if (config->map_height == 0 || config->map == NULL)
	{
		config->map_height = 1;
		config->map = malloc(sizeof(char *));
		config->map_width = line_width;
	}
	else
	{
		if (line_width > config->map_width)
			config->map_width = line_width;
		config->map_height++;
		config->map = ft_realloc(config->map, sizeof(char *)
				* config->map_height);
	}
	config->map[config->map_height - 1] = malloc((line_width + 1)
			* sizeof(char));
	ft_strlcpy(config->map[config->map_height - 1], line, line_width + 1);
	return (0);
}
