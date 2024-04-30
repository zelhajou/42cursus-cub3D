/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:58:53 by zelhajou          #+#    #+#             */
/*   Updated: 2024/04/30 19:55:08 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int validate_no_texture(char *line, t_config *config) {
    if (config->so_texture || config->we_texture || config->ea_texture)
        return printf("Error: NO texture must be defined before SO, WE, or EA texture. NO texture must be defined first\n"), 1;
    if (config->no_texture)
        return printf("Error: NO texture already set\n"), 1;
    if (parse_texture(line, &config->no_texture))
        return 1;
    return 0;
}

int validate_so_texture(char *line, t_config *config) {
    if (!config->no_texture || config->we_texture || config->ea_texture)
        return printf("Error: SO texture must be defined after NO texture and before WE or EA texture. SO texture must be defined after NO texture\n"), 1;
    if (config->so_texture)
        return printf("Error: SO texture already set\n"), 1;
    if (parse_texture(line, &config->so_texture))
        return 1;
    return 0;
}

int validate_we_texture(char *line, t_config *config) {
    if (!config->no_texture || !config->so_texture || config->ea_texture)
        return printf("Error: WE texture must be defined after NO and SO texture and before EA texture. WE texture must be defined after NO and SO texture\n"), 1;
    if (config->we_texture)
        return printf("Error: WE texture already set\n"), 1;
    if (parse_texture(line, &config->we_texture))
        return 1;
    return 0;
}

int validate_ea_texture(char *line, t_config *config) {
    if (!config->no_texture || !config->so_texture || !config->we_texture)
        return printf("Error: EA texture must be defined after NO, SO, and WE texture. EA texture must be defined after NO, SO, and WE texture\n"), 1;
    if (config->ea_texture)
        return printf("Error: EA texture already set\n"), 1;
    if (parse_texture(line, &config->ea_texture))
        return 1;
    return 0;
}

int parse_texture_type(char *line, t_config *config) {
    if (ft_strncmp(line, "NO ", 3) == 0)
        return validate_no_texture(line, config);
    else if (ft_strncmp(line, "SO ", 3) == 0)
        return validate_so_texture(line, config);
    else if (ft_strncmp(line, "WE ", 3) == 0)
        return validate_we_texture(line, config);
    else if (ft_strncmp(line, "EA ", 3) == 0)
        return validate_ea_texture(line, config);
    return 0;
}