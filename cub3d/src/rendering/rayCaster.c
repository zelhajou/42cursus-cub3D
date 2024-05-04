/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 01:31:10 by beddinao          #+#    #+#             */
/*   Updated: 2024/05/03 03:29:34 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	_render(t_map_data *map_data)
{
	t_ptrs			*_ptrs;

	_ptrs = malloc(sizeof(t_ptrs));
	_init(_ptrs, map_data);
	draw_bg(_ptrs, map_data, _ptrs->vertical_level);
	ray_cast(_ptrs);
	mlx_image_to_window(_ptrs->mlx_ptr, _ptrs->mlx_img, 0, 0);
	mlx_key_hook(_ptrs->mlx_ptr, key_handle, _ptrs);
	mlx_mouse_hook(_ptrs->mlx_ptr, mouse_handle, _ptrs);
	mlx_cursor_hook(_ptrs->mlx_ptr, cursor_handle, _ptrs);
	mlx_set_window_limit(_ptrs->mlx_ptr, MIN_WIN_W,
		MIN_WIN_H, MAX_WIN_W, MAX_WIN_H);
	mlx_resize_hook(_ptrs->mlx_ptr, resize_handle, _ptrs);
	mlx_loop(_ptrs->mlx_ptr);
	mlx_terminate(_ptrs->mlx_ptr);
}
