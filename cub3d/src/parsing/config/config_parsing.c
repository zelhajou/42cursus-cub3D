/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:13:14 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/10 11:15:12 by zelhajou         ###   ########.fr       */
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

void	remove_newline_character(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
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
		return (handle_color_line(line, config, map_started));
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
