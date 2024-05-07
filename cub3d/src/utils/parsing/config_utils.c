/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:11:20 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/07 17:16:56 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_config(t_config *config, int *line_number)
{
	config->no_texture = NULL;
	config->we_texture = NULL;
	config->so_texture = NULL;
	config->ea_texture = NULL;
	config->floor_color = 0;
	config->ceiling_color = 0;
	config->map = NULL;
	config->map_height = 0;
	config->map_width = 0;
	*line_number = 1;
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

void	remove_newline_character(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	open_file(const char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Could not open file\n");
		return (-1);
	}
	return (fd);
}
