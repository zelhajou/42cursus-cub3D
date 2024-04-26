/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:52:33 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/26 14:53:47 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Parse the color and fill the color variable
 * 
 * @param line line to parse
 * @param color pointer to the color variable
 * @return int 0 if success, 1 if error
 */
int	parse_color(char *line, int *color)
{
	char	**values;
	char	**color_values;
	size_t	len;

	values = ft_split(line, ' ');
	if (validate_color_format(values))
		return (1);
	len = ft_strlen(values[1]);
	if (values[1][len - 1] == '\n')
		values[1][len - 1] = '\0';
	color_values = ft_split(values[1], ',');
	if (validate_color_values(color_values))
	{
		ft_split_free(values);
		return (1);
	}
	if (validate_digit_values(color_values))
	{
		ft_split_free(values);
		return (1);
	}
	ft_split_free(values);
	return (convert_and_check_range(color_values, color));
}

/**
 * @brief Parse the color type and fill the config struct
 * 
 * @param line line to parse
 * @param config pointer to the config struct
 * @param expected pointer to the expected item
 * @return int 0 if success, 1 if error
 */
int	parse_color_type(char *line, t_config *config, int *expected)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (*expected != 4)
			return (printf("Error: Incorrect order of colors\n"), 1);
		if (parse_color(line, &config->floor_color))
			return (1);
		*expected = 5;
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (*expected != 5)
			return (printf("Error: Incorrect order of colors\n"), 1);
		if (parse_color(line, &config->ceiling_color))
			return (1);
		*expected = 6;
	}
	return (0);
}
