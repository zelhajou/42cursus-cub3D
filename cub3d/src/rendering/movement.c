/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:00:56 by beddinao          #+#    #+#             */
/*   Updated: 2024/05/08 19:52:57 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	update_perspective_movements(t_ptrs *_ptrs, int new_level)
{
	if (new_level > 0 && new_level < _ptrs->win_height)
		_ptrs->vertical_level = new_level;
	perform_ray_cast(_ptrs);
}

void	move_prespective(int keycode, float speed, t_ptrs *_ptrs)
{
	float			old_dir_x;
	float			old_plane_x;
	int				new_level;

	old_dir_x = _ptrs->direction[0];
	old_plane_x = _ptrs->horizontal_camera_plane[0];
	new_level = _ptrs->vertical_level;
	if (keycode == MLX_KEY_DOWN)
		new_level -= 10;
	else if (keycode == MLX_KEY_UP)
		new_level += 10;
	else
	{
		if (keycode == MLX_KEY_LEFT)
			speed *= -1;
		_ptrs->direction[0] = _ptrs->direction[0]
			* cos(speed) - _ptrs->direction[1] * sin(speed);
		_ptrs->direction[1] = old_dir_x * sin(speed)
			+ _ptrs->direction[1] * cos(speed);
		_ptrs->horizontal_camera_plane[0] = _ptrs->horizontal_camera_plane[0]
			* cos(speed) - _ptrs->horizontal_camera_plane[1] * sin(speed);
		_ptrs->horizontal_camera_plane[1] = old_plane_x * sin(speed)
			+ _ptrs->horizontal_camera_plane[1] * cos(speed);
	}
	update_perspective_movements(_ptrs, new_level);
}

void	update_position(t_ptrs *_ptrs, float *new_pos)
{
	int			to_be;

	to_be = 0;
	if (new_pos[0] > 0.0 && new_pos[0] < _ptrs->map_data->map_width
		&& collision_detection(
			_ptrs, new_pos[0], _ptrs->position[1], 0.3))
	{
		_ptrs->position[0] = new_pos[0];
		to_be = 1;
	}
	if (new_pos[1] > 0.0 && new_pos[1] < _ptrs->map_data->map_height
		&& collision_detection(
			_ptrs, _ptrs->position[0], new_pos[1], 0.3))
	{
		_ptrs->position[1] = new_pos[1];
		to_be = 1;
	}
	if (to_be)
		perform_ray_cast(_ptrs);
}

void	move_sides(
		int keycode, t_ptrs *_ptrs, float *new_pos, float speed)
{
	if (keycode == MLX_KEY_D)
	{
		new_pos[0] = _ptrs->position[0]
			+ _ptrs->horizontal_camera_plane[0] * speed;
		new_pos[1] = _ptrs->position[1]
			+ _ptrs->horizontal_camera_plane[1] * speed;
	}
	else
	{
		new_pos[0] = _ptrs->position[0]
			- _ptrs->horizontal_camera_plane[0] * speed;
		new_pos[1] = _ptrs->position[1]
			- _ptrs->horizontal_camera_plane[1] * speed;
	}
}

void	move_position(int keycode, float speed, t_ptrs *_ptrs)
{
	float			new_pos[2];

	if (keycode == MLX_KEY_W)
	{
		new_pos[0] = _ptrs->position[0] + _ptrs->direction[0] * speed;
		new_pos[1] = _ptrs->position[1] + _ptrs->direction[1] * speed;
	}
	else if (keycode == MLX_KEY_S)
	{
		new_pos[0] = _ptrs->position[0] - _ptrs->direction[0] * speed;
		new_pos[1] = _ptrs->position[1] - _ptrs->direction[1] * speed;
	}
	else
		move_sides(keycode, _ptrs, new_pos, speed);
	update_position(_ptrs, new_pos);
}
