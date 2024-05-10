/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 06:08:10 by beddinao          #+#    #+#             */
/*   Updated: 2024/05/10 09:22:13 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# include <time.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "cub3d.h"

# define MAX_WIN_W 1350
# define MIN_WIN_W 500
# define MAX_WIN_H 720
# define MIN_WIN_H 220
# define PPL 2 // 1 <= pixels_per_line <= WIN_W

typedef t_config	t_map_data;

typedef struct ray_data
{
	float			hit_distance;
	int				which_side;
	float			wall_fracs;
	float			wall_height;
	float			ray_direction[2];
	float			position[2];
	float			cell_step[2];
	float			nextline_dist[2];
	int				step[2];
}	t_ray_data;

typedef struct ptrs
{
	mlx_t			*mlx_ptr;
	mlx_image_t		*mlx_img;
	t_map_data		*map_data;
	t_ray_data		*ray_data;
	int32_t			win_height;
	int32_t			win_width;
	// player_properties
	float			position[2];
	float			direction[2];
	float			horizontal_camera_plane[2];
	float			vertical_level;
	// each_pixel
	float			shadow_coef;
	// mouse_data
	int				mouse_pos[2];
	int				mouse_in[2];
	int				mouse_update_rate;
	int				mouse_flag;
	// mini_map
	int				m_width;
	int				m_height;
	int				map_x;
	int				map_y;
	int				wall_color;
	float			player_range;
	float			pixels_per_cell;
	// loaded_textures
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
}	t_ptrs;

void			render_game(t_map_data *F);

//
void			initialize_rendering_engine(t_ptrs *f, t_map_data *ff);
void			perform_ray_cast(t_ptrs *f);
int				calculate_shadowed_texture_color(t_ptrs *f, mlx_texture_t *ff,
					float *fff);
void			draw_map(t_ptrs *f, t_map_data *ff);

// input handling
void			handle_window_resize(int32_t f, int32_t ff, void *fff);
void			handle_cursor_position(double f, double ff, void *fff);
void			handle_mouse_input(mouse_key_t f, action_t ff,
					modifier_key_t fff, void *ffff);
void			handle_key_input(mlx_key_data_t f, void *ff);
void			move_prespective(int f, float ff, t_ptrs *fff);
void			close_handle(void *param);
void			move_position(int f, float ff, t_ptrs *fff);
//
void			adjust_camera_plane(t_ptrs *f);
int				collision_detection(
					t_ptrs *f, float ff, float fff, float ffff);
void			handle_mlx_initialization_error(void);
void			initialize_minimap(t_ptrs *f);
void			initialize_starting_index(t_ptrs *f, t_map_data *ff);
//
int				interpolate_color(int *f, int ff, int fff);
int				compare_float_within_range(float f, float ff, float fff);
int				is_player_character(char f);
mlx_texture_t	*determine_wall_texture(t_ptrs *f, float *ff, t_ray_data *fff);
void			draw_vertical_line(t_ptrs *f, float *ff, int fff);
void			draw_ceiling_line(t_ptrs *_ptrs, float start, int win_x);
void			draw_floor_line(t_ptrs *_ptrs, float end, int win_x);
void			draw_line(t_ptrs *_ptrs, mlx_texture_t *tex,
					float *y_line, float *tex_position);
void			draw_pixel(t_ptrs *_ptrs, int x, int y, int color);

#endif
