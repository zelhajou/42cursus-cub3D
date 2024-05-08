/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 01:31:10 by beddinao          #+#    #+#             */
/*   Updated: 2024/05/08 19:54:26 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	render_game(t_map_data *map_data)
{
	t_ptrs			*_ptrs;

	_ptrs = malloc(sizeof(t_ptrs));
	initialize_rendering_engine(_ptrs, map_data);
	perform_ray_cast(_ptrs);
	mlx_image_to_window(_ptrs->mlx_ptr, _ptrs->mlx_img, 0, 0);
	mlx_key_hook(_ptrs->mlx_ptr, handle_key_input, _ptrs);
	mlx_mouse_hook(_ptrs->mlx_ptr, handle_mouse_input, _ptrs);
	mlx_cursor_hook(_ptrs->mlx_ptr, handle_cursor_position, _ptrs);
	mlx_resize_hook(_ptrs->mlx_ptr, handle_window_resize, _ptrs);
	mlx_set_window_limit(_ptrs->mlx_ptr, MIN_WIN_W,
		MIN_WIN_H, MAX_WIN_W, MAX_WIN_H);
	mlx_close_hook(_ptrs->mlx_ptr, close_handle, _ptrs);
	mlx_loop(_ptrs->mlx_ptr);
}
