/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:56:49 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/06 14:58:46 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_texture(char *line)
{
	return (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0);
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
