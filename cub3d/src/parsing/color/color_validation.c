/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:52:59 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/01 18:06:38 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_color_format(char **values)
{
	if (!values || ft_split_count(values) != 2)
	{
		printf("Error: Invalid color format\n");
		if (values)
			ft_split_free(values);
		return (1);
	}
	return (0);
}

int	validate_color_values(char **color_values)
{
	if (!color_values || ft_split_count(color_values) != 3)
	{
		printf("Error: Invalid color format (must be R,G,B)\n");
		if (color_values)
			ft_split_free(color_values);
		return (1);
	}
	return (0);
}

int	validate_digit_values(char **color_values)
{
	if (!is_all_digits(color_values[0]) || !is_all_digits(color_values[1])
		|| !is_all_digits(color_values[2]))
	{
		printf("Error: Color values must be digits\n");
		ft_split_free(color_values);
		return (1);
	}
	return (0);
}

int	validate_floor_color(char *line, t_config *config)
{
	if (config->floor_color)
		return (printf("Error: Floor color already set\n"), 1);
	if (parse_color(line, &config->floor_color))
		return (1);
	return (0);
}

int	validate_ceiling_color(char *line, t_config *config)
{
	if (config->ceiling_color)
		return (printf("Error: Ceiling color already set\n"), 1);
	if (parse_color(line, &config->ceiling_color))
		return (1);
	return (0);
}
