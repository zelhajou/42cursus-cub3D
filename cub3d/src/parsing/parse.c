/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:13:14 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/22 15:05:01 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_texture(char *line, char **texture)
{
	(void)line;
	(void)texture;
	return (0);
}

int parse_color(char *line, int *color)
{
	(void)line;
	(void)color;
	return (0);
}

int parse_map_line(char *line, char **map)
{
	(void)line;
	(void)map;
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
	while (get_next_line(fd, &line) > 0)
	{
		
		// parse line
		
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}