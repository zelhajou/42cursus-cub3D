/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:21:09 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/22 16:38:47 by zelhajou         ###   ########.fr       */
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

typedef struct s_config
{
	char *no_texture;
	char *we_texture;
	char *so_texture;
	char *ea_texture;
	int floor_color;
	int ceiling_color;
	char **map;
} t_config;


int parse_config_file(const char *file_path, t_config *config);



#endif