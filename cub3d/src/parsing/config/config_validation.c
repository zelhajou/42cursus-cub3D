/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:55:52 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/08 15:43:34 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_extension(const char *file_path)
{
	if (ft_strncmp(file_path + ft_strlen(file_path) - 4, ".cub", 4) != 0)
	{
		printf("Error: Invalid file extension. ");
		printf("File must have a .cub extension\n");
		return (1);
	}
	return (0);
}

int	check_path_validity(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Invalid path '%s'\n", path);
		return (1);
	}
	close(fd);
	return (0);
}

bool	has_unexpected_data(const char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0
		|| ft_strncmp(line, "1", 1) == 0
		|| ft_strncmp(line, "0", 1) == 0)
		return (false);
	return (true);
}

int	check_config_validity(int map_started, t_config *config)
{
	if (!config->no_texture || !config->we_texture
		|| !config->so_texture || !config->ea_texture
		|| config->floor_color == -1 || config->ceiling_color == -1
		|| !map_started)
		return (printf("Error: Missing data\n"), 1);
	return (0);
}

int	is_empty_or_whitespace(const char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (1);
}
