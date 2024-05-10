/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:21:09 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/10 11:49:08 by zelhajou         ###   ########.fr       */
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
# include <limits.h>

// ANSI colors
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

// Struct to store the configuration
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
/**
 * Config file Parsing: config_file_parsing.c
**/
int		parse_config_file(const char *file_path, t_config *config,
			int *line_number);
int		read_and_parse_lines(int fd, t_config *config, int *line_number);
int		parse_line_data(char *line, t_config *config, int *map_started);
/**
 * Config file validation: config_file_validation.c
**/
int		check_file_extension(const char *file_path);
int		check_path_validity(const char *path);
bool	has_unexpected_data(const char *line);
int		check_config_validity(int map_started, t_config *config);
int		is_empty_or_whitespace(const char *line);

/*------------------ Parsing textures ------------------*/
/**
 * Parsing textures: texture_parsing.c
*/
int		handle_texture_line(char *line, t_config *config, int *map_started);
int		parse_texture_type(char *line, t_config *config);
int		parse_texture(char *line, char **texture);
/**
 * Parsing textures validation: texture_validation.c
*/
bool	is_texture(char *line);
int		validate_no_texture(char *line, t_config *config);
int		validate_so_texture(char *line, t_config *config);
int		validate_we_texture(char *line, t_config *config);
int		validate_ea_texture(char *line, t_config *config);

/*------------------ Parsing colors ---------------------*/
/**
 * Parsing colors: color_parsing.c
*/
int		handle_color_line(char *line, t_config *config, int *map_started);
int		parse_color_type(char *line, t_config *config);
int		parse_color(char *line, int *color);
int		convert_and_check_range(char **color_values, int *color);
int		count_commas(char *str);
/**
 * Parsing colors validation: color_validation.c
*/
bool	is_color(char *line);
int		is_all_digits(const char *str);
int		validate_color_format(char **values);
int		validate_color_values(char **color_values);
int		validate_digit_values(char **color_values);

/*------------------ Parsing map ------------------------*/
/**
 * Parsing map: map_parsing.c
*/
int		handle_map_line(char *line, t_config *config, int *map_started);
/**
 * Parsing map: map_validation.c and map_validation2.c
*/
int		is_valid_map(t_config *config);
int		fill_map_with_spaces(t_config *config);
int		is_map_rectangle(t_config *config);
int		check_top_bottom(t_config *config);
int		check_left_right(t_config *config);
int		is_space_within_map_bounds(size_t i, size_t j,
			t_config *config, char **map_copy);
int		check_empty_space(t_config *config);
int		is_valid_map_char(t_config *config);
int		is_player_position_valid(t_config *config);

/*------------------ Utils -----------------------------*/
/**
 * Config utils: config_utils.c
*/
void	init_config(t_config *config, int *line_number);
void	free_texture(char **texture);
void	free_map(t_config *config);
void	free_config(t_config *config);
/**
 * Error utils: error_utils.c
*/
void	print_error_with_caret(const char *line);
void	handle_mlx_initialization_error(void);

/******************* Raycasting functions ******************/
void	render_game(t_config *_ptrs);

#endif
