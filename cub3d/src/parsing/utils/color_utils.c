/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:52:59 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/29 10:23:22 by zelhajou         ###   ########.fr       */
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

int	is_all_digits(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
