/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 01:30:14 by beddinao          #+#    #+#             */
/*   Updated: 2024/05/03 01:34:06 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	cancel_d(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(1);
}

void	adapt_camera_plane(t_ptrs	*_ptrs)
{
	_ptrs->horizontal_camera_plane[0] = _ptrs->direction[1] * -1;
	_ptrs->horizontal_camera_plane[1] = _ptrs->direction[0];
}

int	better_collision_detection(
		t_ptrs *_ptrs, float newX, float newY, float range)
{
	float			y;
	float			x;

	y = newY - range;
	while (y < newY + range)
	{
		x = newX - range;
		while (x < newX + range)
		{
			if (_ptrs->map_data->map[(int)y][(int)x] == '1')
				return (0);
			x += range / 2;
		}
		y += range / 2;
	}
	return (1);
}
