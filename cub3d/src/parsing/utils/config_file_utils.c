/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_file_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:55:52 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/29 10:23:48 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	is_empty_or_whitespace(const char *line)
{
	while (*line)
	{
		if (!isspace(*line))
			return (0);
		line++;
	}
	return (1);
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

bool has_unexpected_data(const char *line)
{
	while (*line && isspace(*line))
		line++;
	if (strncmp(line, "NO ", 3) == 0 ||
		strncmp(line, "WE ", 3) == 0 ||
		strncmp(line, "SO ", 3) == 0 ||
		strncmp(line, "EA ", 3) == 0 ||
		strncmp(line, "F ", 2) == 0 ||
		strncmp(line, "C ", 2) == 0 ||
		strncmp(line, "1", 1) == 0 ||
		strncmp(line, "0", 1) == 0)
		return (false);
	return (true);
}
