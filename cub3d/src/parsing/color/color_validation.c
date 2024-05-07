/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:52:59 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/07 17:08:30 by zelhajou         ###   ########.fr       */
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

bool	is_color(char *line)
{
	char	**values;

	values = ft_split(line, ' ');
	if (!values || ft_split_count(values) != 2)
	{
		ft_split_free(values);
		return (false);
	}
	if (ft_strncmp(values[0], "F", 2) != 0
		&& ft_strncmp(values[0], "C", 2) != 0)
	{
		ft_split_free(values);
		return (false);
	}
	ft_split_free(values);
	return (true);
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
