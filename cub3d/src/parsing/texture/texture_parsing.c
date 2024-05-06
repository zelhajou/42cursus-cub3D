/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:58:53 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/06 14:57:42 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	ft_split_free(values);
	if ((!*texture) || check_path_validity(*texture))
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
	if (strcmp(values[0], "NO") == 0)
		return (validate_no_texture(line, config));
	else if (strcmp(values[0], "SO") == 0)
		return (validate_so_texture(line, config));
	else if (strcmp(values[0], "WE") == 0)
		return (validate_we_texture(line, config));
	else if (strcmp(values[0], "EA") == 0)
		return (validate_ea_texture(line, config));
	ft_split_free(values);
	return (0);
}
