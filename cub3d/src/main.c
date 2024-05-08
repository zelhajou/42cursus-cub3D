/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:42:45 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/08 11:42:21 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_config	*config;
	int			line_number;

	config = (t_config *)malloc(sizeof(t_config));
	if (argc == 2 && !check_path_validity(argv[1]) && config)
	{
		init_config(config, &line_number);
		if (parse_config_file(argv[1], config, &line_number))
		{
			free_config(config);
			return (1);
		}
		render_game(config);
	}
	return (0);
}
