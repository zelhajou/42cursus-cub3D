/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:56:49 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/01 17:58:38 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_no_texture(char *line, t_config *config)
{
	if (config->so_texture || config->we_texture || config->ea_texture)
	{
		printf("Error: NO texture must be defined before ");
		printf("SO, WE, and EA texture.\n");
		return (1);
	}
	if (config->no_texture)
		return (printf("Error: NO texture already set\n"), 1);
	if (parse_texture(line, &config->no_texture))
		return (1);
	return (0);
}

int	validate_so_texture(char *line, t_config *config)
{
	if (!config->no_texture || config->we_texture || config->ea_texture)
	{
		printf("Error: SO texture must be defined after NO texture ");
		printf("and before WE and EA texture.\n");
		return (1);
	}
	if (config->so_texture)
		return (printf("Error: SO texture already set\n"), 1);
	if (parse_texture(line, &config->so_texture))
		return (1);
	return (0);
}

int	validate_we_texture(char *line, t_config *config)
{
	if (!config->no_texture || !config->so_texture || config->ea_texture)
	{
		printf("Error: WE texture must be defined after NO and SO texture ");
		printf("and before EA texture.\n");
		return (1);
	}
	if (config->we_texture)
		return (printf("Error: WE texture already set\n"), 1);
	if (parse_texture(line, &config->we_texture))
		return (1);
	return (0);
}

int	validate_ea_texture(char *line, t_config *config)
{
	if (!config->no_texture || !config->so_texture || !config->we_texture)
	{
		printf("Error: EA texture must be defined after");
		printf("NO, SO, and WE texture.\n");
		return (1);
	}
	if (config->ea_texture)
		return (printf("Error: EA texture already set\n"), 1);
	if (parse_texture(line, &config->ea_texture))
		return (1);
	return (0);
}
