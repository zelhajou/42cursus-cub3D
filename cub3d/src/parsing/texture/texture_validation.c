/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:56:49 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/10 11:05:04 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_texture(char *line)
{
	char	*line_trimmed;

	line_trimmed = ft_strtrim(line, " ");
	if (!line_trimmed)
		return (false);
	if (ft_strncmp(line_trimmed, "NO", 2) == 0
		|| ft_strncmp(line_trimmed, "SO", 2) == 0
		|| ft_strncmp(line_trimmed, "WE", 2) == 0
		|| ft_strncmp(line_trimmed, "EA", 2) == 0)
	{
		free(line_trimmed);
		return (true);
	}
	free(line_trimmed);
	return (false);
}

int	validate_no_texture(char *line, t_config *config)
{
	if (config->no_texture)
		return (printf("Error: NO texture already set\n"), 1);
	if (parse_texture(line, &config->no_texture))
		return (1);
	return (0);
}

int	validate_so_texture(char *line, t_config *config)
{
	if (config->so_texture)
		return (printf("Error: SO texture already set\n"), 1);
	if (parse_texture(line, &config->so_texture))
		return (1);
	return (0);
}

int	validate_we_texture(char *line, t_config *config)
{
	if (config->we_texture)
		return (printf("Error: WE texture already set\n"), 1);
	if (parse_texture(line, &config->we_texture))
		return (1);
	return (0);
}

int	validate_ea_texture(char *line, t_config *config)
{
	if (config->ea_texture)
		return (printf("Error: EA texture already set\n"), 1);
	if (parse_texture(line, &config->ea_texture))
		return (1);
	return (0);
}
