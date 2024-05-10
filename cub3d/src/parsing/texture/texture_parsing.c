/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:58:53 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/10 11:21:09 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_texture_line(char *line, t_config *config, int *map_started)
{
	if (*map_started)
		return (printf("Error: Map must be defined in the end\n"), 1);
	if (config->no_texture && config->we_texture
		&& config->so_texture && config->ea_texture)
		return (printf("Error: Textures already set\n"), 1);
	if (parse_texture_type(line, config))
		return (1);
	return (0);
}

int	parse_texture_type(char *line, t_config *config)
{
	char	**values;

	values = ft_split(line, ' ');
	if (!values || ft_split_count(values) != 2)
	{
		printf("Error: Invalid texture format\n");
		if (values)
			ft_split_free(values);
		return (1);
	}
	if (ft_strncmp(values[0], "NO", 2) == 0)
		return (ft_split_free(values), validate_no_texture(line, config));
	else if (ft_strncmp(values[0], "SO", 2) == 0)
		return (ft_split_free(values), validate_so_texture(line, config));
	else if (ft_strncmp(values[0], "WE", 2) == 0)
		return (ft_split_free(values), validate_we_texture(line, config));
	else if (ft_strncmp(values[0], "EA", 2) == 0)
		return (ft_split_free(values), validate_ea_texture(line, config));
	ft_split_free(values);
	return (0);
}

int	is_png(char *texture)
{
	int	i;

	i = ft_strlen(texture) - 4;
	if (i < 0)
		return (1);
	if (ft_strncmp(&texture[i], ".png", 4) != 0)
	{
		printf("Error: Invalid texture format\n");
		return (1);
	}
	return (0);
}

int	parse_texture(char *line, char **texture)
{
	char	**values;

	values = ft_split(line, ' ');
	if (!values || ft_split_count(values) != 2)
	{
		printf("Error: Invalid texture format\n");
		if (values)
			ft_split_free(values);
		return (1);
	}
	*texture = ft_strdup(values[1]);
	if (!*texture)
	{
		ft_split_free(values);
		return (1);
	}
	ft_split_free(values);
	if ((!*texture) || check_path_validity(*texture) || is_png(*texture))
		return (1);
	return (0);
}
