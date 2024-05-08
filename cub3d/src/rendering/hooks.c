/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 01:30:34 by beddinao          #+#    #+#             */
/*   Updated: 2024/05/08 19:54:05 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	handle_key_input(mlx_key_data_t keydata, void *param)
{
	t_ptrs			*_ptrs;

	_ptrs = (t_ptrs *)param;
	if (keydata.action == MLX_RELEASE)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_handle(_ptrs);
	else if (keydata.key == MLX_KEY_RIGHT
		|| keydata.key == MLX_KEY_LEFT
		|| keydata.key == MLX_KEY_UP
		|| keydata.key == MLX_KEY_DOWN)
		move_prespective(keydata.key, 0.05, _ptrs);
	else if (keydata.key == MLX_KEY_W
		|| keydata.key == MLX_KEY_A
		|| keydata.key == MLX_KEY_D
		|| keydata.key == MLX_KEY_S)
		move_position(keydata.key, 0.2, _ptrs);
}

void	handle_mouse_input(
		mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_ptrs		*_ptrs;

	(void)mods;
	_ptrs = (t_ptrs *)param;
	if (button == MLX_MOUSE_BUTTON_LEFT)
	{
		if (action == MLX_PRESS)
		{
			_ptrs->mouse_in[0] = _ptrs->mouse_pos[0];
			_ptrs->mouse_in[1] = _ptrs->mouse_pos[1];
			_ptrs->mouse_flag = 1;
			_ptrs->wall_color = 0xacacac;
			_ptrs->player_range = 0.8;
		}
		else if (action == MLX_RELEASE)
		{
			_ptrs->mouse_flag = 0;
			_ptrs->wall_color = 0x595959;
			_ptrs->player_range = 0.4;
			perform_ray_cast(_ptrs);
		}
	}
}

void	update_perspective_hooks(int *distance_v, int *direction_v,
			t_ptrs *_ptrs)
{
	float			coef;

	if (distance_v[0] < 0)
	{
		direction_v[0] = MLX_KEY_LEFT;
		distance_v[0] *= -1;
	}
	if (distance_v[1] < 0)
	{
		direction_v[1] = MLX_KEY_UP;
		distance_v[1] *= -1;
	}
	if (distance_v[0] > 1)
	{
		coef = fabs(1.0 * ((float)distance_v[0] / (float)_ptrs->win_width));
		move_prespective(direction_v[0], coef / 1.5, _ptrs);
		_ptrs->mouse_update_rate = 0;
	}
	if (distance_v[1] > 1)
	{
		coef = fabs(1.0 * ((float)distance_v[1] / (float)_ptrs->win_height));
		move_prespective(direction_v[1], coef / 1.5, _ptrs);
		_ptrs->mouse_update_rate = 0;
	}
}

void	handle_cursor_position(double posX, double posY, void *param)
{
	t_ptrs			*_ptrs;
	int				distance_v[2];
	int				direction_v[2];

	_ptrs = (t_ptrs *)param;
	direction_v[0] = MLX_KEY_RIGHT;
	direction_v[1] = MLX_KEY_DOWN;
	if (posX > 0 && posX < _ptrs->win_width
		&& posY > 0 && posY < _ptrs->win_height)
	{
		if (_ptrs->mouse_flag && _ptrs->mouse_update_rate > 1)
		{
			distance_v[0] = posX - _ptrs->mouse_in[0];
			distance_v[1] = posY - _ptrs->mouse_in[1];
			update_perspective_hooks(distance_v, direction_v, _ptrs);
		}
		else
			_ptrs->mouse_update_rate += 1;
		_ptrs->mouse_pos[0] = posX;
		_ptrs->mouse_pos[1] = posY;
		if (_ptrs->mouse_flag)
			draw_pixel(_ptrs, posX, posY, 0xFFFFFFFF);
	}
}

void	handle_window_resize(int32_t width, int32_t height, void *param)
{
	t_ptrs			*_ptrs;

	_ptrs = (t_ptrs *)param;
	if (mlx_resize_image(_ptrs->mlx_img, width, height))
	{
		_ptrs->win_height = height;
		_ptrs->win_width = width;
		_ptrs->vertical_level = height / 2;
		initialize_minimap(_ptrs);
		perform_ray_cast(_ptrs);
	}
}
