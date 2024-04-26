/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:58:53 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/26 16:28:10 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Parse the texture and fill the texture variable
 * 
 * @param line line to parse
 * @param texture pointer to the texture variable
 * @return int 0 if success, 1 if error
 */
int	parse_texture(char *line, char **texture)
{
	char	**values;
	size_t	len;

	values = ft_split(line, ' ');
	if (!values || ft_split_count(values) != 2)
	{
		printf("Error: Invalid texture format\n");
		if (values)
			ft_split_free(values);
		return (1);
	}
	len = ft_strlen(values[1]);
	if (values[1][len - 1] == '\n')
		values[1][len - 1] = '\0';
	*texture = ft_strdup(values[1]);
	ft_split_free(values);
	if (!*texture || check_path_validity(*texture))
		return (1);
	return (0);
}

/**
 * @brief Parse the texture type and fill the config struct
 * 
 * @param line line to parse
 * @param config pointer to the config struct
 * @param expected pointer to the expected item
 * @return int 0 if success, 1 if error
 */
int	parse_texture_type(char *line, t_config *config, int *expected)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (*expected != 0)
			return (printf("Error: Incorrect order of texture paths\n"), 1);
		if (parse_texture(line, &config->no_texture))
			return (1);
		*expected = 1;
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (*expected != 1)
			return (printf("Error: Incorrect order of texture paths\n"), 1);
		if (parse_texture(line, &config->we_texture))
			return (1);
		*expected = 2;
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (*expected != 2)
			return (printf("Error: Incorrect order of texture paths\n"), 1);
		if (parse_texture(line, &config->so_texture))
			return (1);
		*expected = 3;
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (*expected != 3)
			return (printf("Error: Incorrect order of texture paths\n"), 1);
		if (parse_texture(line, &config->ea_texture))
			return (1);
		*expected = 4;
	}
	return (0);
}
