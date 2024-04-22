/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:42:45 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/22 16:28:51 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_config config;
	
	if (argc != 2)
	{
		printf("Error: Incorrect number of arguments\n");
		return (1);
	}
	if (parse_config_file(argv[1], &config))
	{
		printf("Error: Could not parse config file\n");
		return (1);
	}
		
	return (0);
}