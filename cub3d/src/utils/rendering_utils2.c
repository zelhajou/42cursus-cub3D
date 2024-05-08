/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 01:32:04 by beddinao          #+#    #+#             */
/*   Updated: 2024/05/08 19:55:22 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

mlx_texture_t	*determine_wall_texture(
		t_ptrs *_ptrs, float *rayDir, t_ray_data *ray_data)
{
	int			side;

	side = ray_data->which_side;
	if (!side && rayDir[0] < 0)
		return (_ptrs->east);
	else if (!side && rayDir[0] > 0)
		return (_ptrs->west);
	else if (side && rayDir[1] < 0)
		return (_ptrs->south);
	else if (side && rayDir[1] > 0)
		return (_ptrs->north);
	return (NULL);
}

int	compare_float_within_range(float f1, float f2, float range)
{
	if (f1 > f2 - range && f1 < f2 + range)
		return (1);
	return (0);
}

int	is_player_character(char p)
{
	if (p == 'N' || p == 'W' || p == 'E' || p == 'S')
		return (1);
	return (0);
}

int	interpolate_color(int *range, int index, int color)
{
	int			colors[2][3];
	float		coef;

	if (index == range[0])
		return (color);
	coef = fabs(1.0 * (range[1] - index) / (range[1] - range[0]));
	colors[0][0] = color >> 16;
	colors[0][1] = (color & 0xFFFF) >> 8;
	colors[0][2] = color & 0xFF;
	colors[1][0] = (int)(colors[0][0] * coef);
	colors[1][1] = (int)(colors[0][1] * coef);
	colors[1][2] = (int)(colors[0][2] * coef);
	return ((colors[1][0] << 16) + (colors[1][1] << 8) + colors[1][2]);
}

int	calculate_shadowed_texture_color(
		t_ptrs *_ptrs, mlx_texture_t *tex, float *texYaxis)
{
	int		index;
	int		r;
	int		g;
	int		b;

	index = (int)texYaxis[0] + tex->width
		* tex->bytes_per_pixel * (int)texYaxis[1];
	r = (int)(tex->pixels[index] * _ptrs->shadow_coef) << 16;
	g = (int)(tex->pixels[index + 1] * _ptrs->shadow_coef) << 8;
	b = (int)(tex->pixels[index + 2] * _ptrs->shadow_coef);
	return (r | g | b);
}
