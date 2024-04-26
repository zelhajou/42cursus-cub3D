/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_file_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:55:52 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/26 16:27:38 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Open the file and return the file descriptor
 * 
 * @param file_path path to the file
 * @return int file descriptor
 */
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

/**
 * @brief Check if the file extension is valid
 * 
 * @param file_path path to the file
 * @return int 0 if success, 1 if error
 */
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

/**
 * @brief Check if the string is empty or whitespace
 * 
 * @param line string to check
 * @return int 0 if success, 1 if error
 */
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

/**
 * @brief Check if the path is valid
 * 
 * @param path path to check
 * @return int 0 if success, 1 if error
 */
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
