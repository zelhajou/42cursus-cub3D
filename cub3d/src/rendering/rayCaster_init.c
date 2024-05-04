/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCaster_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 01:31:51 by beddinao          #+#    #+#             */
/*   Updated: 2024/05/04 15:42:32 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	tetermine_direction(t_ptrs *_ptrs, char dire)
{
	_ptrs->direction[0] = 0;
	_ptrs->direction[1] = -1;
	if (dire == 'W')
	{
		_ptrs->direction[0] -= 1;
		_ptrs->direction[1] += 1;
	}
	else if (dire == 'E')
	{
		_ptrs->direction[0] += 1;
		_ptrs->direction[1] += 1;
	}
	else if (dire == 'S')
		_ptrs->direction[1] += 2;
}

void	load_textures(t_ptrs *_ptrs, t_map_data *map_data)
{
	_ptrs->north = mlx_load_png(map_data->no_texture);
	_ptrs->south = mlx_load_png(map_data->so_texture);
	_ptrs->west = mlx_load_png(map_data->we_texture);
	_ptrs->east = mlx_load_png(map_data->ea_texture);
}

void	_adapt_indx_s(t_ptrs *_ptrs, t_map_data *map_data)
{
	int			x;
	int			y;

	y = 0;
	_ptrs->mouse_flag = 0;
	_ptrs->mouse_update_rate = 0;
	while (y < map_data->map_height)
	{
		x = 0;
		while (x < map_data->map_width)
		{
			if (is_player_char(map_data->map[y][x]))
			{
				_ptrs->position[0] = x + 0.5;
				_ptrs->position[1] = y + 0.5;
				tetermine_direction(_ptrs, map_data->map[y][x]);
				adapt_camera_plane(_ptrs);
				_ptrs->vertical_level = _ptrs->win_height / 2;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	init_mini_map(t_ptrs *_ptrs)
{
	_ptrs->wall_color = 0x595959;
	_ptrs->player_range = 0.4;
	_ptrs->pixels_per_cell = (_ptrs->win_width / _ptrs->map_data->map_width) / 5;
	if (_ptrs->pixels_per_cell > 20)
		_ptrs->pixels_per_cell = 20.0;
	_ptrs->map_y = _ptrs->win_height - (_ptrs->map_data->map_height
			* _ptrs->pixels_per_cell) - _ptrs->pixels_per_cell * 2;
	_ptrs->map_x = _ptrs->pixels_per_cell * 2;
	_ptrs->m_width = _ptrs->map_data->map_width * _ptrs->pixels_per_cell;
	_ptrs->m_height = _ptrs->map_data->map_height * _ptrs->pixels_per_cell;
}

void	print_map(t_map_data	*map_data)
{
	int		y = 0;

	printf("-->(%zu, %zu)\n", map_data->map_width, map_data->map_height);
	while (y < map_data->map_height)
	{
		printf("|%s| -> %zu\n", map_data->map[y], ft_strlen(map_data->map[y]));
		y++;
	}
}

void	_init(t_ptrs *_ptrs, t_map_data *map_data)
{
	_ptrs->win_width = MAX_WIN_W;
	_ptrs->win_height = MAX_WIN_H;
	_ptrs->map_data = map_data;
	print_map(map_data);
	_adapt_indx_s(_ptrs, map_data);
	init_mini_map(_ptrs);
	_ptrs->mlx_ptr = mlx_init(_ptrs->win_width,
			_ptrs->win_height, "CUBED", true);
	if (!_ptrs->mlx_ptr)
		cancel_d();
	_ptrs->mlx_img = mlx_new_image(_ptrs->mlx_ptr,
			_ptrs->win_width, _ptrs->win_height);
	if (!_ptrs->mlx_img)
		cancel_d();
	load_textures(_ptrs, map_data);
}
