/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:58:53 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/04 18:03:13 by beddinao         ###   ########.fr       */
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
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (validate_no_texture(line, config));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (validate_so_texture(line, config));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (validate_we_texture(line, config));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (validate_ea_texture(line, config));
	return (0);
}
