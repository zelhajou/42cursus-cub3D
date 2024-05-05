/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCaster_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 01:31:35 by beddinao          #+#    #+#             */
/*   Updated: 2024/05/05 11:21:00 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	draw_(
		t_ptrs *_ptrs, int win_x, mlx_texture_t *tex, t_ray_data *ray_data)
{
	float		tex_position[2];
	float		tex_y_index;
	float		y_line[3];

	y_line[0] = _ptrs->vertical_level - ray_data->wall_height;
	y_line[1] = _ptrs->vertical_level + ray_data->wall_height;
	y_line[2] = y_line[1] - y_line[0];
	if (!tex || y_line[2] < _ptrs->win_height / 2 / 5)
		return (draw_vertical_line(_ptrs, y_line, win_x, 0x000000FF));
	tex_position[0] = (int)(ray_data->wall_fracs
			* (float)tex->width) * tex->bytes_per_pixel;
	tex_position[1] = 0;
	tex_y_index = 1.0 * (tex->height / y_line[2]);
	_ptrs->shadow_coef = 1.0 * ray_data->wall_height / (_ptrs->win_height / 2);
	if (_ptrs->shadow_coef > 1)
		_ptrs->shadow_coef = 1.0;
	while (y_line[0] < y_line[1] && tex_position[1] < tex->height)
	{
		if (y_line[0] > 0.0 && y_line[0] < _ptrs->win_height)
			mlx_put_pixel(_ptrs->mlx_img, win_x, y_line[0],
				get_texture_color(_ptrs, tex, tex_position, y_line) 
				<< 8 | 0xFF);
		y_line[0] += 1;
		tex_position[1] += tex_y_index;
	}
}

void	initialize_ray_data(t_ray_data *ray_data, size_t *position, float *fPosition)
{
	int			i;

	i = 0;
	ray_data->which_side = 1;
	while (i < 2)
	{
		ray_data->cell_step[i] = fabs(1 / ray_data->ray_direction[i]);
		if (ray_data->ray_direction[i] < 0)
		{
			ray_data->step[i] = -1;
			ray_data->nextline_dist[i] = (fPosition[i]
					- (float)position[i]) * ray_data->cell_step[i];
		}
		else
		{
			ray_data->step[i] = 1;
			ray_data->nextline_dist[i] = ((float)(position[i] + 1)
					- fPosition[i]) * ray_data->cell_step[i];
		}
		i++;
	}
}

void	gather_ray_data(t_ptrs *_ptrs, t_ray_data *ray_data, float *fPosition)
{
	int			i;

	i = 1;
	if (ray_data->which_side)
		i = 0;
	ray_data->hit_distance = ray_data->nextline_dist[ray_data->which_side]
		- ray_data->cell_step[ray_data->which_side];
	ray_data->wall_fracs = fPosition[i]
		+ ray_data->hit_distance * ray_data->ray_direction[i];
	ray_data->wall_height = (_ptrs->win_height / 2) / ray_data->hit_distance;
	ray_data->wall_fracs = ray_data->wall_fracs - (int)ray_data->wall_fracs;
}

void	get_wall_distance(t_ptrs *_ptrs, t_ray_data *ray_data, size_t *position, float *fPosition)
{
	initialize_ray_data(ray_data, position, fPosition);
	while (position[0] > 0 && position[1] > 0
		&& position[0] < _ptrs->map_data->map_width && position[1] < _ptrs->map_data->map_height)
	{
		if (ray_data->nextline_dist[0] < ray_data->nextline_dist[1])
		{
			ray_data->nextline_dist[0] += ray_data->cell_step[0];
			position[0] += ray_data->step[0];
			ray_data->which_side = 0;
		}
		else
		{
			ray_data->nextline_dist[1] += ray_data->cell_step[1];
			position[1] += ray_data->step[1];
			ray_data->which_side = 1;
		}
		mlx_put_pixel(_ptrs->mlx_img,
			_ptrs->map_x + (position[0] * _ptrs->pixels_per_cell),
			_ptrs->map_y + (position[1] * _ptrs->pixels_per_cell), 0xff0000FF);
		if (_ptrs->map_data->map[position[1]][position[0]] == '1')
			break ;
	}
}

void	ray_cast(t_ptrs	*_ptrs)
{
	float		camera_plane_x;
	size_t			position[2];
	int			x_pixel;
	t_ray_data	*ray_data;

	x_pixel = 0;
	clock_t	st = clock();
	ray_data = _ptrs->ray_data = malloc(sizeof(t_ray_data));
	while (x_pixel < _ptrs->win_width)
	{
		camera_plane_x = 2 * x_pixel / ((float)_ptrs->win_width) - 1;
		ray_data->ray_direction[0] = _ptrs->direction[0]
			+ _ptrs->horizontal_camera_plane[0] * camera_plane_x;
		ray_data->ray_direction[1] = _ptrs->direction[1]
			+ _ptrs->horizontal_camera_plane[1] * camera_plane_x;
		position[0] = (int)_ptrs->position[0];
		position[1] = (int)_ptrs->position[1];
		get_wall_distance(_ptrs, ray_data, position, _ptrs->position);
		gather_ray_data(_ptrs, ray_data, _ptrs->position);
		draw_(_ptrs, x_pixel, tetermine_texture(_ptrs, ray_data->ray_direction, ray_data),
			ray_data);
		x_pixel += 1;
	}
	draw_map(_ptrs, _ptrs->map_data);
	printf("---> scene rendered in %f\n", (double)(clock()-st)/CLOCKS_PER_SEC);
	free(ray_data);
}
