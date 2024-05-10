/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:56:29 by beddinao          #+#    #+#             */
/*   Updated: 2024/05/10 08:59:26 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	draw_vertical_line(t_ptrs *_ptrs, float *Yaxis, int win_x)
{
	int			y;
	int			x;

	y = Yaxis[0];
	while (y < Yaxis[1])
	{
		x = win_x;
		while (x < win_x + PPL)
			draw_pixel(_ptrs, x++, y, 0x000000);
		y++;
	}
}

void	draw_ceiling_line(t_ptrs *_ptrs, float start, int win_x)
{
	int			y;
	int			x;

	y = 0;
	while (y < start)
	{
		x = win_x;
		while (x < win_x + PPL)
			mlx_put_pixel(_ptrs->mlx_img, x++, y,
				_ptrs->map_data->ceiling_color << 8 | 0xFF);
		y++;
	}
}

void	draw_floor_line(t_ptrs *_ptrs, float end, int win_x)
{
	int			y;
	int			x;

	y = (int)end;
	while (y < _ptrs->win_height)
	{
		x = win_x;
		while (x < win_x + PPL)
			mlx_put_pixel(_ptrs->mlx_img, x++, y,
				_ptrs->map_data->floor_color << 8 | 0xFF);
		y++;
	}
}

void	draw_line(
		t_ptrs *_ptrs, mlx_texture_t *tex, float *y_line, float *tex_position)
{
	int			win_x;
	int			color;
	int			x;

	win_x = (int)tex_position[1];
	tex_position[1] = 0;
	if (y_line[0] < 0)
	{
		tex_position[1] = tex_position[2] * (y_line[0] * -1);
		y_line[0] = 0;
	}
	if (y_line[1] > _ptrs->win_height)
		y_line[1] = _ptrs->win_height;
	draw_ceiling_line(_ptrs, y_line[0], win_x);
	while (y_line[0] < y_line[1] && tex_position[1] < tex->height)
	{
		x = win_x;
		color = calculate_shadowed_texture_color(_ptrs, tex, tex_position);
		while (x < win_x + PPL)
			mlx_put_pixel(_ptrs->mlx_img, x++, y_line[0], color << 8 | 0xFF);
		tex_position[1] += tex_position[2];
		y_line[0] += 1;
	}
	draw_floor_line(_ptrs, y_line[1], win_x);
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
			if (compare_float_within_range(_ptrs->position[0],
					x / _ptrs->pixels_per_cell, _ptrs->player_range)
				&& compare_float_within_range(_ptrs->position[1],
					y / _ptrs->pixels_per_cell, _ptrs->player_range))
				color = 0x0168b7;
			else if (map_data->map[(int)(y / _ptrs->pixels_per_cell)]
					[(int)(x / _ptrs->pixels_per_cell)] == '1')
				color = _ptrs->wall_color;
			else
				continue ;
			draw_pixel(_ptrs, x + _ptrs->map_x, y + _ptrs->map_y, color);
		}
	}
}
