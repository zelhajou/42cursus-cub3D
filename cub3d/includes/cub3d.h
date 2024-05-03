/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:21:09 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/03 20:37:03 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <get_next_line.h>
# include <libft.h>
# include <stdbool.h>
# include <ctype.h>

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct s_config
{
	char	*no_texture;
	char	*we_texture;
	char	*so_texture;
	char	*ea_texture;
	int		floor_color;
	int		ceiling_color;
	char	**map;
	char	**map_copy;
	size_t	map_width;
	size_t	map_height;
	int		map_started;
}	t_config;

/******************* Parsing functions ******************/

/*------------------ Parsing config file ---------------*/
// Config file Parsing: config_file_parsing.c
int		parse_config_file(const char *file_path, t_config *config,
			int *line_number);
int		read_and_parse_lines(int fd, t_config *config, int *line_number);
int		parse_line_data(char *line, t_config *config, int *map_started);
// Config file utils: config_file_utils.c
void	free_config(t_config *config);
void	remove_newline_character(char *line);
bool	has_unexpected_data(const char *line);
int		check_config_validity(int map_started, t_config *config);
void print_error_with_caret(const char *line);
// Cofig file validation: config_file_validation.c
int		open_file(const char *file_path);
int		check_file_extension(const char *file_path);
int		is_empty_or_whitespace(const char *line);
int		check_path_validity(const char *path);
// Config line handlers: config_line_handlers.c
int		handle_texture_line(char *line, t_config *config, int *map_started);
int		handle_color_line(char *line, t_config *config);
int		handle_map_line(char *line, t_config *config, int *map_started);

/*------------------ Parsing textures ------------------*/
// Parsing textures: parse_texture.c
int		parse_texture(char *line, char **texture);
int		parse_texture_type(char *line, t_config *config);
// Parsing textures validation: texture_validation.c
int		validate_no_texture(char *line, t_config *config);
int		validate_so_texture(char *line, t_config *config);
int		validate_we_texture(char *line, t_config *config);
int		validate_ea_texture(char *line, t_config *config);
// Parsing textures utils: texture_utils.c
bool	is_texture(char *line);

/*------------------ Parsing colors ---------------------*/
// Parsing colors: color_parsing.c
int		parse_color(char *line, int *color);
int		parse_color_type(char *line, t_config *config);
// Parsing colors utils: color_utils.c
int		convert_and_check_range(char **color_values, int *color);
int		is_all_digits(const char *str);
bool	is_color(char *line);
int		count_commas(char *str);
// Parsing colors validation: color_validation.c
int		validate_color_format(char **values);
int		validate_color_values(char **color_values);
int		validate_digit_values(char **color_values);
int		validate_floor_color(char *line, t_config *config);
int		validate_ceiling_color(char *line, t_config *config);

/*------------------ Parsing map ------------------------*/

/*------------------ Player position -------------------*/


#endif