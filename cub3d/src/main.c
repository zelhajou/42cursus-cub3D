/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:42:45 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/04 22:19:34 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void display_config(t_config *config)
{
	printf("NO texture: %s\n", config->no_texture);
	printf("WE texture: %s\n", config->we_texture);
	printf("SO texture: %s\n", config->so_texture);
	printf("EA texture: %s\n", config->ea_texture);
	printf("Floor color: %d\n", config->floor_color);
	printf("Ceiling color: %d\n", config->ceiling_color);
	printf("Map:\n");
	for (size_t i = 0; i < config->map_height; i++)
		printf("%s\n", config->map[i]);
	printf("config->map_height: %zu\n", config->map_height);
	printf("config->map_width: %zu\n", config->map_width);
}

int	display_error_message(t_config *config)
{
	printf("\n----------------------------------------\n");
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
	free(config);
	return (1);
}*/

void	init_config(t_config *config, int *line_number)
{
	config->no_texture = NULL;
	config->we_texture = NULL;
	config->so_texture = NULL;
	config->ea_texture = NULL;
	config->floor_color = 0;
	config->ceiling_color = 0;
	config->map = NULL;
	config->map_height = 0;
	config->map_width = 0;
	*line_number = 1;
}

void	leaks_fun()
{
	system("leaks cub3d");
}

int	main(int argc, char **argv)
{
	t_config		*config;
	int		line_number;

	atexit(leaks_fun);
	config = NULL;
	if (argc == 2 && !check_path_validity(argv[1])
		&& (config = malloc(sizeof(t_config))))
	{
		init_config(config, &line_number);
		if (parse_config_file(argv[1], config, &line_number))
			return free(config), (1);
		//
		_render(config);
	}
	return (0);
}
