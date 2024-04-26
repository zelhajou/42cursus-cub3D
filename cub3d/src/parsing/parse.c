/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:13:14 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/26 16:11:29 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Parse the config file and fill the config struct
 * 
 * @param file_path path to the config file
 * @param config pointer to the config struct
 * @return int 0 if success, 1 if error
 */
int	parse_config_file(const char *file_path, t_config *config)
{
	int		fd;
	int		expected_item;

	if (check_file_extension(file_path))
		return (1);
	fd = open_file(file_path);
	if (fd == -1)
		return (1);
	expected_item = 0;
	if (read_and_parse_lines(fd, config, &expected_item))
	{
		close(fd);
		return (1);
	}
	close(fd);
	if (handle_errors_and_cleanup(expected_item, config))
		return (1);
	return (0);
}

/**
 * @brief Read and parse the lines of the config file
 * 
 * @param fd file descriptor
 * @param config pointer to the config struct
 * @param expected_item pointer to the expected item
 * @return int 0 if success, 1 if error
 */
int	read_and_parse_lines(int fd, t_config *config, int *expected_item)
{
	char	*line;

	while (line = get_next_line(fd))
	{
		if (is_empty_or_whitespace(line))
		{
			free(line);
			continue ;
		}
		if (parse_line_data(line, config, expected_item))
		{
			free(line);
			return (1);
		}
		free(line);
	}
	return (0);
}

/**
 * @brief Parse the line data
 * 
 * @param line line to parse
 * @param config pointer to the config struct
 * @param expected pointer to the expected item
 * @return int 0 if success, 1 if error
 */
int	parse_line_data(char *line, t_config *config, int *expected)
{
	if (parse_texture_type(line, config, expected)
		|| parse_color_type(line, config, expected))
		return (1);
	return (0);
}

/**
 * @brief Handle errors and cleanup
 * 
 * @param fd file descriptor
 * @param expected_item expected item
 * @param config pointer to the config struct
 * @return int 0 if success, 1 if error
 */
int	handle_errors_and_cleanup(int expected_item, t_config *config)
{
	if (expected_item != 6)
	{
		if (expected_item < 4)
			printf("Error: Missing texture paths\n");
		else if (expected_item < 5)
			printf("Error: Missing floor color\n");
		else if (expected_item < 6)
			printf("Error: Missing ceiling color\n");
		else
			printf("Error: Missing map data\n");
		free_config(config);
		return (1);
	}
	return (0);
}
