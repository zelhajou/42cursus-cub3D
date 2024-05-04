/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 01:32:04 by beddinao          #+#    #+#             */
/*   Updated: 2024/05/04 17:46:41 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	draw_vertical_line(t_ptrs *_ptrs, float *Yaxis, int x, int color)
{
	int			y;

	y = Yaxis[0];
	while (y < Yaxis[1])
	{
		if (x > 0 && y > 0 && x < _ptrs->win_width && y < _ptrs->win_height)
			mlx_put_pixel(_ptrs->mlx_img, x, y, color);
		y++;
	}
}

mlx_texture_t	*tetermine_texture(
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

int	compare_f(float f1, float f2, float range)
{
	if (f1 > f2 - range && f1 < f2 + range)
		return (1);
	return (0);
}

int	darken_color(int *range, int index, int color)
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

void	draw_bg(t_ptrs *_ptrs, t_map_data *map_data, int margin)
{
	int				y;
	int				x;

	y = 0;
	while (y < _ptrs->win_height)
	{
		x = 0;
		while (x < _ptrs->win_width)
		{
			if (y < margin)
				mlx_put_pixel(_ptrs->mlx_img, x, y,
					map_data->ceiling_color << 8 | 0xFF);
			else
				mlx_put_pixel(_ptrs->mlx_img, x, y,
					map_data->floor_color << 8 | 0xFF);
			x++;
		}
		y++;
	}
}
