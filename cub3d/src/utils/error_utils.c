/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:49:10 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/10 11:05:40 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine.h"

void	print_error_with_caret(const char *line)
{
	int		error_message_len;
	int		i;

	i = 0;
	line = ft_strtrim(line, " ");
	if (!line)
	{
		printf("Error: Invalid data\n");
		return ;
	}
	error_message_len = ft_strlen("Error: Invalid data ");
	printf("Error: Invalid data '%s'\n", line);
	while (i < error_message_len)
	{
		printf(" ");
		i++;
	}
	printf(ANSI_COLOR_GREEN"\e[1m^\n\e[m "ANSI_COLOR_RESET);
	free((char *)line);
}

void	handle_mlx_initialization_error(void)
{
	printf("Error initializing MLX: \n\t%s\n", mlx_strerror(mlx_errno));
	exit(1);
}
