/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_file_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:13:14 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/05 10:20:40 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Fill the map with spaces
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

// print the copied map
void print_copied_map(t_config *config)
{
	size_t i;
	size_t height = config->map_height;

	i = 0;
	printf("Copied map:\n");
	while (i < height)
	{
		printf("%s\n", config->map_copy[i]);
		i++;
	}
	
}

// Check if the map is rectangle
int is_map_rectangle(t_config *config)
{
	size_t i;
	size_t height = config->map_height;
	size_t width = config->map_width;

	i = 0;
	while (i < height)
	{
		if (ft_strlen(config->map_copy[i]) != width)
		{
			printf("Error: Map is not a rectangle\n");
			return 1;
		}
		i++;
	}
	return 0;
}

// Check top and bottom of map have only '1' and ' '
int check_top_bottom(t_config *config)
{
	size_t j;
	size_t height = config->map_height;
	size_t width = config->map_width;

	for (j = 0; j < width; j++)
	{
		if (config->map_copy[0][j] != '1' && config->map_copy[0][j] != ' ')
		{
			printf("Error: Map is not surrounded by walls\n");
			return 1;
		}
		if (config->map_copy[height - 1][j] != '1' && config->map_copy[height - 1][j] != ' ')
		{
			printf("Error: Map is not surrounded by walls\n");
			return 1;
		}
	}
	return 0;
}

// check when found an empty space, it is surrounded by walls
int check_empty_space(t_config *config)
{
	size_t i, j;
	size_t height = config->map_height;
	size_t width = config->map_width;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (config->map_copy[i][j] == ' ')
			{
				if (i > 0 && config->map_copy[i - 1][j] != '1' && config->map_copy[i - 1][j] != ' ')
				{
					printf("Error: Map is not surrounded by walls\n");
					return 1;
				}
				if (i < height - 1 && config->map_copy[i + 1][j] != '1' && config->map_copy[i + 1][j] != ' ')
				{
					printf("Error: Map is not surrounded by walls\n");
					return 1;
				}
				if (j > 0 && config->map_copy[i][j - 1] != '1' && config->map_copy[i][j - 1] != ' ')
				{
					printf("Error: Map is not surrounded by walls\n");
					return 1;
				}
				if (j < width - 1 && config->map_copy[i][j + 1] != '1' && config->map_copy[i][j + 1] != ' ')
				{
					printf("Error: Map is not surrounded by walls\n");
					return 1;
				}
			}
		}
	}
	return 0;
}

// check if any character is not '1', '0', 'N', 'S', 'W', 'E' or ' '
int is_valid_map_char(t_config *config)
{
	size_t i, j;
	size_t height = config->map_height;
	size_t width = config->map_width;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (config->map_copy[i][j] != '1' && config->map_copy[i][j] != '0' && config->map_copy[i][j] != 'N' && config->map_copy[i][j] != 'S' && config->map_copy[i][j] != 'W' && config->map_copy[i][j] != 'E' && config->map_copy[i][j] != ' ') {
				printf("Error: Invalid character in the map\n");
				printf("Character: %c\n", config->map_copy[i][j]);
				return 1;
			}
		}
	}
	return 0;
}

// Check if player position is valid
int is_player_position_valid(t_config *config)
{
	size_t i, j;
	size_t height = config->map_height;
	size_t width = config->map_width;

	int player_found = 0;
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (ft_strchr("NSWE", config->map_copy[i][j]))
			{
				if (player_found) {
					printf("Error: More than one player position found\n");
					return 1;
				}
				player_found = 1;
			}
		}
	}
	// Check if player position is found
	if (!player_found) {
		printf("Error: No player position found\n");
		return 1;
	}
	return 0;
}

// free the copied map
void free_copied_map(t_config *config)
{
	size_t i;
	size_t height = config->map_height;

	for (i = 0; i < height; i++)
	{
		//printf("|%s| -> %i\n", config->map_copy[i], ft_strlen(config->map_copy[i]));
		free(config->map[i]);
	}
	free(config->map);
	config->map = config->map_copy;
}
////
int	check_start_end(t_config *config)
{
	int		y;
	int		x[2];
	int		i;
	
	y = 0;
	while (y < config->map_height)
	{
		x[0] = 0;
		x[1] = ft_strlen(config->map[y]) - 1;
		while (x[0] < config->map_width && config->map[y][x[0]] == ' ')
			x[0]++;
		while (x[1] && config->map[y][x[1]] == ' ')
			x[1]--;
		printf("got |%c|, |%c|\n", config->map[y][x[0]], config->map[y][x[1]]);
		if (x[0] > x[1] || config->map[y][x[0]] != '1'
			|| config->map[y][x[1]] != '1')
			return (1);
		y++;
	}
	return (0);
}
////
int is_valid_map(t_config *config)
{
	// Fill the map with spaces
	if (fill_map_with_spaces(config))
		return (1);
	// check if the map is a rectangle
	if (is_map_rectangle(config))
		return (1);
	//print_copied_map(config);
	// Check top and bottom of map have only '1' and ' '
	if (check_top_bottom(config) || check_start_end(config))
		return (1);
	// Check when found an empty space, it is surrounded by walls
	if (check_empty_space(config))
		return (1);
	// check if any character is not '1', '0', 'N', 'S', 'W', 'E' or ' '
	if (is_valid_map_char(config))
		return (1);
	// Check if player position is valid
	if (is_player_position_valid(config))
		return (1);
	// print the copied map
	//print_copied_map(config);
	// free the copied map
	free_copied_map(config);
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
	if (check_config_validity(map_started, config))
		return (1);
	if (is_valid_map(config))
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
	{
		print_error_with_caret(line);
		return (1);
	}
	else
	{
		printf("Error: Invalid line '%s'\n", line);
		return (1);
	}
	return (0);
}
