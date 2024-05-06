/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_file_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:13:14 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/06 20:42:44 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * fill the map with spaces
*/
// int fill_map_with_spaces(t_config *config)
// {
// 	size_t	i;
// 	size_t	height;
// 	size_t	width;

// 	i = 0;
// 	height = config->map_height;
// 	width = config->map_width;
// 	config->map_copy = malloc(height * sizeof(char*));
// 	if (!config->map_copy)
// 		return (1);
// 	while (i < height)
// 	{
// 		config->map_copy[i] = malloc((width + 1) * sizeof(char));
// 		if (!config->map_copy[i])
// 			return (1);
// 		ft_memset(config->map_copy[i], ' ', width);
// 		config->map_copy[i][width] = '\0';
// 		i++;
// 	}
// 	i = 0;
// 	while (i < height)
// 	{
// 		ft_strlcpy(config->map_copy[i], config->map[i], width + 1);
// 		i++;
// 	}
// 	return (0);
// }

int fill_map_with_spaces(t_config *config)
{
	size_t i = 0;
	size_t height = config->map_height;
	size_t width = config->map_width;

	config->map_copy = malloc(height * sizeof(char*));
	if (!config->map_copy)
		return (1);
	for (i = 0; i < height; i++)
	{
		config->map_copy[i] = malloc((width + 1) * sizeof(char));
		if (!config->map_copy[i])
			return (1);
		memset(config->map_copy[i], ' ', width);
		config->map_copy[i][width] = '\0';
	}
	// Copy the original map into the map copy
	for (i = 0; i < height; i++)
	{
		strncpy(config->map_copy[i], config->map[i], strlen(config->map[i]));
	}
	return (0);
}


/**
 * Check when found an empty space in the map, must be surrounded by 1 or ' '
*/
int check_empty_space(t_config *config)
{
	size_t i;
	size_t j;
	size_t height;
	size_t width;

	i = 0;
	j = 0;
	height = config->map_height;
	width = config->map_width;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (config->map_copy[i][j] == ' ')
			{
				if (i > 0 && config->map_copy[i - 1][j] != '1'
					&& config->map_copy[i - 1][j] != ' ')
					return (printf("Error: Map is not surrounded by walls\n"), 1);
				if (i < height - 1 && config->map_copy[i + 1][j] != '1'
					&& config->map_copy[i + 1][j] != ' ')
					return (printf("Error: Map is not surrounded by walls\n"), 1);
				if (j > 0 && config->map_copy[i][j - 1] != '1'
					&& config->map_copy[i][j - 1] != ' ')
					return (printf("Error: Map is not surrounded by walls\n"), 1);
				if (j < width - 1 && config->map_copy[i][j + 1] != '1'
					&& config->map_copy[i][j + 1] != ' ')
					return (printf("Error: Map is not surrounded by walls\n"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// check if any character is not '1', '0', 'N', 'S', 'W', 'E' or ' '
int is_valid_map_char(t_config *config)
{
	size_t i, j;
	size_t height = config->map_height;
	size_t width = config->map_width;

	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (config->map_copy[i][j] != '1' && config->map_copy[i][j] != '0'
				&& config->map_copy[i][j] != 'N' && config->map_copy[i][j] != 'S'
				&& config->map_copy[i][j] != 'W' && config->map_copy[i][j] != 'E'
				&& config->map_copy[i][j] != ' ')
			{
				printf("Error: Invalid character in the map\n");
				printf("Character: %c\n", config->map_copy[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// Check if player position is valid
int is_player_position_valid(t_config *config)
{
	size_t	i;
	size_t	j;
	size_t	height;
	size_t	width;
	int		player_found;

	i = 0;
	j = 0;
	height = config->map_height;
	width = config->map_width;
	player_found = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (ft_strchr("NSWE", config->map_copy[i][j]))
			{
				if (player_found)
					return (printf("Error: More than one player position found\n"), 1);
				player_found = 1;
			}
			j++;
		}
		i++;
	}
	if (!player_found)
		return (printf("Error: No player position found\n"), 1);
	return (0);
}

// free the copied map
void free_copied_map(t_config *config)
{
	size_t i;
	size_t height = config->map_height;

	i = 0;
	while (i < height)
	{
		free(config->map[i]);
		i++;
	}
	free(config->map);
}




int is_valid_map(t_config *config)
{
	// Fill the map with spaces
	if (fill_map_with_spaces(config))
		return (1);
	printf("Map:\n");
	print_copied_map(config);
	// check if the map is a rectangle
	if (is_map_rectangle(config))
		return (1);
	// Check map is surrounded by walls
	if (check_top_bottom(config) || check_left_right(config))
		return (1);
	// Check when found an empty space, must be surrounded by 1 or ' '
	if (check_empty_space(config))
		return (1);
	// check if any character is not '1', '0', 'N', 'S', 'W', 'E' or ' '
	if (is_valid_map_char(config))
		return (1);
	// Check if player position is valid
	if (is_player_position_valid(config))
		return (1);
	// free the map
	free_map(config);
	config->map = config->map_copy;
	return 0;
}

int	parse_config_file(const char *file_path, t_config *config, int *line_number)
{
	int		fd;

	if (check_file_extension(file_path))
		return (1);
	fd = open_file(file_path);
	if (fd == -1)
		return (1);
	if (read_and_parse_lines(fd, config, line_number))
	{
		close(fd);
		printf("%s:%d ", file_path, *line_number);
		printf(ANSI_COLOR_RED"\e[1merror:\e[m "ANSI_COLOR_RESET);
		printf("\e[1mCould not parse the config file\e[m\n");
		return (1);
	}
	close(fd);
	return (0);
}

int	read_and_parse_lines(int fd, t_config *config, int *line_number)
{
	char	*line;
	int		map_started;

	map_started = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_empty_or_whitespace(line) && !map_started)
		{
			free(line);
			(*line_number)++;
			continue ;
		}
		remove_newline_character(line);
		if (parse_line_data(line, config, &map_started))
			return (free(line), 1);
		free(line);
		(*line_number)++;
	}
	if (check_config_validity(map_started, config) || is_valid_map(config))
		return (1);
	return (0);
}

int	parse_line_data(char *line, t_config *config, int *map_started)
{
	if (is_texture(line))
		return (handle_texture_line(line, config, map_started));
	else if (is_color(line))
		return (handle_color_line(line, config));
	else if (ft_strchr("01 ", *line))
		return (handle_map_line(line, config, map_started));
	else if (*map_started && !is_texture(line)
		&& !is_color(line)
		&& !ft_strchr("01 ", *line))
		return (print_error_with_caret(line), 1);
	else
		return (print_error_with_caret(line), 1);
	return (0);
}
