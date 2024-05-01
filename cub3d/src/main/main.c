/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:42:45 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/01 18:08:27 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void display_error_message(void)
{
	printf("----------------------------------------\n");
	printf("| Example of a valid config file:      |\n");
	printf("----------------------------------------\n");
	printf("| Command   | Description              |\n");
	printf("----------------------------------------\n");
	printf("| NO        | North-facing texture     |\n");
	printf("| SO        | South-facing texture     |\n");
	printf("| WE        | West-facing texture      |\n");
	printf("| EA        | East-facing texture      |\n");
	printf("| F         | Floor color (RGB)        |\n");
	printf("| C         | Ceiling color (RGB)      |\n");
	printf("| Map       | ASCII representation     |\n");
	printf("|           | of the map               |\n");
	printf("----------------------------------------\n");
}

int	main(int argc, char **argv)
{
	t_config	config;
	int	line_number = 1;

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
	config.no_texture = NULL;
	config.we_texture = NULL;
	config.so_texture = NULL;
	config.ea_texture = NULL;
	config.floor_color = 0;
	config.ceiling_color = 0;
	if (parse_config_file(argv[1], &config, &line_number))
	{
		//display_error_message();
		return (1);
	}
	printf("NO texture: %s\n" , config.no_texture);
	printf("WE texture: %s\n", config.we_texture);
	printf("SO texture: %s\n", config.so_texture);
	printf("EA texture: %s\n", config.ea_texture);
	printf("Floor color: %d\n", config.floor_color);
	printf("Ceiling color: %d\n", config.ceiling_color);
	return (0);
}
