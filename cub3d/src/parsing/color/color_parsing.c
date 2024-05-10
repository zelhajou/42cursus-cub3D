/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:52:33 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/10 11:45:57 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_color_line(char *line, t_config *config, int *map_started)
{
	if (*map_started)
		return (printf("Error: Map must be defined in the end\n"), 1);
	if (config->floor_color != -1 && ft_strchr(line, 'F'))
		return (printf("Error: Floor color already set\n"), 1);
	if (config->ceiling_color != -1 && ft_strchr(line, 'C'))
		return (printf("Error: Ceiling color already set\n"), 1);
	if (parse_color_type(line, config))
		return (1);
	return (0);
}

int	parse_color_type(char *line, t_config *config)
{
	char	**values;

	values = ft_split(line, ' ');
	if (!values || ft_split_count(values) != 2)
	{
		printf("Error: Invalid color format\n");
		if (values)
			ft_split_free(values);
		return (1);
	}
	if (ft_strncmp(values[0], "F", 1) == 0)
	{
		if (parse_color(line, &config->floor_color))
			return (ft_split_free(values), 1);
	}
	else if (ft_strncmp(values[0], "C", 1) == 0)
	{
		if (parse_color(line, &config->ceiling_color))
			return (ft_split_free(values), 1);
	}
	return (ft_split_free(values), 0);
}

int	parse_color(char *line, int *color)
{
	char	**values;
	char	**color_values;
	int		comma_count;

	comma_count = 0;
	values = ft_split(line, ' ');
	if (validate_color_format(values))
		return (1);
	comma_count = count_commas(values[1]);
	if (comma_count > 2)
	{
		printf("Error: Invalid color format\n");
		return (ft_split_free(values), 1);
	}
	color_values = ft_split(values[1], ',');
	if (validate_color_values(color_values))
		return (ft_split_free(values), 1);
	if (validate_digit_values(color_values))
		return (ft_split_free(values), 1);
	ft_split_free(values);
	return (convert_and_check_range(color_values, color));
}

int	convert_and_check_range(char **color_values, int *color)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(color_values[0]);
	g = ft_atoi(color_values[1]);
	b = ft_atoi(color_values[2]);
	ft_split_free(color_values);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		printf("Error: Color values must be between 0 and 255\n");
		return (1);
	}
	*color = (r << 16) + (g << 8) + b;
	return (0);
}

int	count_commas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}
