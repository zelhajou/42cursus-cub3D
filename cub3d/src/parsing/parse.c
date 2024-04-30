/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:13:14 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/30 19:57:05 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_config_validity(int map_started, t_config *config) {
    if (!config->no_texture || !config->we_texture || !config->so_texture || !config->ea_texture || !config->floor_color || !config->ceiling_color || !map_started) {
        printf("Error: Missing elements in config file or incorrect order\n");
        return 1;
    }
    return 0;
}

int	parse_config_file(const char *file_path, t_config *config)
{
	int		fd;

	if (check_file_extension(file_path))
		return (1);
	fd = open_file(file_path);
	if (fd == -1)
		return (1);
	if (read_and_parse_lines(fd, config))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	read_and_parse_lines(int fd, t_config *config)
{
	char	*line;
	int		map_started = 0;

	while ((line = get_next_line(fd)))
	{
		if (is_empty_or_whitespace(line))
		{
			free(line);
			continue ;
		}
		if (parse_line_data(line, config, &map_started))
		{
			free(line);
			return (1);
		}
		free(line);
	}
	if (check_config_validity(map_started, config))
		return (1);
	return (0);
}

bool is_texture(char *line) {
	return (ft_strncmp(line, "NO ", 3) == 0 || 
			ft_strncmp(line, "WE ", 3) == 0 || 
			ft_strncmp(line, "SO ", 3) == 0 || 
			ft_strncmp(line, "EA ", 3) == 0);
}

bool is_color(char *line) {
	return (ft_strncmp(line, "F ", 2) == 0 || 
			ft_strncmp(line, "C ", 2) == 0);
}

int	parse_line_data(char *line, t_config *config, int *map_started)
{
	if (is_texture(line))
	{
		if (config->no_texture && config->we_texture && config->so_texture && config->ea_texture)
			return (printf("Error: Textures already set\n"), 1);
		if (config->floor_color || config->ceiling_color || *map_started)
			return (printf("Error: Texture must be defined before colors or map\n"), 1);
		if (parse_texture_type(line, config))
			return (1);
	}
	else if (is_color(line))
	{
		if (config->floor_color && config->ceiling_color)
			return (printf("Error: Colors already set\n"), 1);
		if (!config->no_texture || !config->we_texture || !config->so_texture || !config->ea_texture)
			return (printf("Error: Colors must be defined after textures\n"), 1);
		if (parse_color_type(line, config))
			return (1);
	}
	else if (ft_strchr("01 ", *line))
	{
		if (!config->no_texture || !config->we_texture || !config->so_texture || !config->ea_texture || !config->floor_color || !config->ceiling_color)
			return (printf("Error: Map must be defined after textures and colors\n"), 1);
		*map_started = 1;
		printf("Map: %s\n", line);
		// Parse map
	}
	else if (map_started && !is_texture(line) && !is_color(line))
	{
		printf("Error: Invalid line\n");
		return (1);
	}
	else
	{
		printf("Error: Invalid line\n");
		return (1);
	}
	return (0);
}
