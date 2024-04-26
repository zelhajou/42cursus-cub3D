/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:42:45 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/26 11:01:48 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_config	config;

	if (argc != 2)
	{
		printf("Error: Incorrect number of arguments\n");
		return (1);
	}
	if (check_path_validity(argv[1]))
	{
		printf("Error: Could not open file\n");
		return (1);
	}

	if (parse_config_file(argv[1], &config))
	{
		printf("Error: Could not parse config file\n");
		return (1);
	}

	
	printf("NO texture: %s\n", config.no_texture);
	printf("WE texture: %s\n", config.we_texture);
	printf("SO texture: %s\n", config.so_texture);
	printf("EA texture: %s\n", config.ea_texture);
	printf("Floor color: %d\n", config.floor_color);
	printf("Ceiling color: %d\n", config.ceiling_color);
	return (0);
}