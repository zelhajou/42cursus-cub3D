/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:13:14 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/22 18:31:23 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_texture(char *line, char **texture)
{

	(void)texture;
	printf("Texture: %s\n", line);
	
	return (0);
}

int parse_color(char *line, int *color)
{
	(void)color;
	printf("Color: %s\n", line);
	return (0);
}

int parse_map_line(char *line, char **map)
{
	(void)map;
	printf("Map: %s\n", line);
	return (0);
}

int	parse_config_file(const char *file_path, t_config *config)
{
	int		fd;
	char 	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Could not open file\n");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		if (line[0] == 'N' && line[1] == 'O')
			parse_texture(line, &config->no_texture);
		else if (line[0] == 'W' && line[1] == 'E')
			parse_texture(line, &config->we_texture);
		else if (line[0] == 'S' && line[1] == 'O')
			parse_texture(line, &config->so_texture);
		else if (line[0] == 'E' && line[1] == 'A')
			parse_texture(line, &config->ea_texture);
		else if (line[0] == 'F' && line[1] == ' ')
			parse_color(line, &config->floor_color);
		else if (line[0] == 'C' && line[1] == ' ')
			parse_color(line, &config->ceiling_color);
		else if (strchr(" 012NSEW", line[0]))
			parse_map_line(line, config->map);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}