/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCaster_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 06:05:18 by beddinao          #+#    #+#             */
/*   Updated: 2024/05/04 15:27:30 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	get_texture_color(
		t_ptrs *_ptrs, mlx_texture_t *tex, float *texYaxis, float *y_line)
{
	int		index;
	int		r;
	int		g;
	int		b;
	float	coef;

	coef = fabs((_ptrs->shadow_coef * 1.0
				* ((y_line[1] - y_line[0]) / y_line[2])) + 0.1);
	if (!_ptrs->ray_data->which_side)
		coef -= 0.1;
	index = (int)texYaxis[0] + tex->width
		* tex->bytes_per_pixel * (int)texYaxis[1];
	r = (int)(tex->pixels[index] * coef) << 16;
	g = (int)(tex->pixels[index + 1] * coef) << 8;
	b = (int)(tex->pixels[index + 2] * coef);
	return (r | g | b);
}

void	draw_map(t_ptrs *_ptrs, t_map_data *map_data)
{
	int		color;
	int		x;
	int		y;

	y = -1;
	while (++y < _ptrs->m_height)
	{
		x = -1;
		while (++x < _ptrs->m_width)
		{
			if (compare_f(_ptrs->position[0],
					x / _ptrs->pixels_per_cell, _ptrs->player_range)
				&& compare_f(_ptrs->position[1],
					y / _ptrs->pixels_per_cell, _ptrs->player_range))
				color = 0x0168b7;
			else if (map_data->map[(int)(y / _ptrs->pixels_per_cell)]
					[(int)(x / _ptrs->pixels_per_cell)] == '1')
				color = _ptrs->wall_color;
			else
				continue ;
			mlx_put_pixel(_ptrs->mlx_img, (int)x + _ptrs->map_x,
				(int)y + _ptrs->map_y, color << 8 | 0xFF);
		}
	}
}

int	is_player_char(char p)
{
	if (p == 'N' || p == 'W' || p == 'E' || p == 'S')
		return (1);
	return (0);
}
