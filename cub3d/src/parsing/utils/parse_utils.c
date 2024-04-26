/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:11:20 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/26 16:26:14 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Free the config struct
 * 
 * @param config pointer to the config struct
 */
void	free_config(t_config *config)
{
	int	i;

	i = 0;
	if (config->no_texture)
	{
		free(config->no_texture);
		config->no_texture = NULL;
	}
	if (config->we_texture)
	{
		free(config->we_texture);
		config->we_texture = NULL;
	}
	if (config->so_texture)
	{
		free(config->so_texture);
		config->so_texture = NULL;
	}
	if (config->ea_texture)
	{
		free(config->ea_texture);
		config->ea_texture = NULL;
	}
	if (config->map)
	{
		while (config->map[i])
		{
			free(config->map[i]);
			config->map[i] = NULL;
			i++;
		}
		free(config->map);
		config->map = NULL;
	}
}
