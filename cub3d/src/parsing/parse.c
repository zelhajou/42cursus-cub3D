/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:13:14 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/21 10:19:02 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_config_file(const char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error while opening the file\n");
		return (1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		/* Here we will parse the file line by line and check for errors
		in the file format and store the data in the game struct */
		
		printf("%s\n", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}