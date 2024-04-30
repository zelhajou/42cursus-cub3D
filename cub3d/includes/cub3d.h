/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:21:09 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/30 19:39:03 by zelhajou         ###   ########.fr       */
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

typedef struct s_config
{
	char	*no_texture;
	char	*we_texture;
	char	*so_texture;
	char	*ea_texture;
	int		floor_color;
	int		ceiling_color;
	char	**map;
	int		map_width;
	int		map_height;
	int		map_started;
} t_config;


/****************** Parsing functions ******************/

/*------------------ Parsing config file ------------------*/
// Parsing config file: parse.c
int		parse_config_file(const char *file_path, t_config *config);
int		read_and_parse_lines(int fd, t_config *config);
int parse_line_data(char *line, t_config *config, int *map_started);
// config file utils: config_file_utils.c
int		check_file_extension(const char *file_path);
int		open_file(const char *file_path);
int		is_empty_or_whitespace(const char *line);
int		check_path_validity(const char *path);

/*------------------ Parsing textures ------------------*/
// Parsing textures: parse_texture.c
int		parse_texture(char *line, char **texture);
int		parse_texture_type(char *line, t_config *config);

/*------------------ Parsing colors ------------------*/
// Parsing colors: parse_color.c
int		parse_color(char *line, int *color);
int		parse_color_type(char *line, t_config *config);
// Parsing colors utils: color_utils.c
int		validate_color_format(char **values);
int		validate_color_values(char **color_values);
int		is_all_digits(const char *str);
int		validate_digit_values(char **color_values);
int		convert_and_check_range(char **color_values, int *color);

/****************** Utils ******************/
// Parsing Utils: parse_utils.c
void	free_config(t_config *config);

#endif