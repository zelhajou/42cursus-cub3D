/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:52:33 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/01 18:07:34 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	parse_color_type(char *line, t_config *config)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		return (validate_floor_color(line, config));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (validate_ceiling_color(line, config));
	return (0);
}
