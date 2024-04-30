/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:52:33 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/30 19:54:59 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_color(char *line, int *color)
{
	char	**values;
	char	**color_values;
	size_t	len;
	int j = 0;

	values = ft_split(line, ' ');
	if (validate_color_format(values))
		return (1);
	len = ft_strlen(values[1]);
	if (values[1][len - 1] == '\n')
		values[1][len - 1] = '\0';
	// check the count of the ,
	for (size_t i = 0; values[1][i]; i++)
	{
		if (values[1][i] == ',')
			j++;
		if (j > 2)
		{
			printf("Error: Invalid color format\n");
			ft_split_free(values);
			return (1);
		}
	}
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

int validate_floor_color(char *line, t_config *config)
{
    if (config->floor_color) 
        return (printf("Error: Floor color already set\n"), 1);
    if (parse_color(line, &config->floor_color))
        return (1);
    return 0;
}

int validate_ceiling_color(char *line, t_config *config)
{
    if (config->ceiling_color)
	{
        printf("Error: Ceiling color already set\n");
        return (1);
    }
    if (parse_color(line, &config->ceiling_color))
        return (1);
    return (0);
}

int parse_color_type(char *line, t_config *config) {
    if (ft_strncmp(line, "F ", 2) == 0)
        return validate_floor_color(line, config);
    else if (ft_strncmp(line, "C ", 2) == 0)
        return validate_ceiling_color(line, config);
    return 0;
}