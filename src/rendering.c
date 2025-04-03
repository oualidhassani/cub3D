/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:21:00 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 18:30:15 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

static void	init_wall_data(t_wall_data *data, t_mlx *mlx, t_ray *ray)
{
	data->perp_distance = calculate_perp_distance(ray,
			mlx->player.rotation_angle);
	data->proj_plane = (WINDOW_WIDTH / 2.0f) / tan(mlx->player.fov / 2.0f);
	data->proj_height = (TILE_SIZE / data->perp_distance) * data->proj_plane;
	data->strip_height = (int)data->proj_height;
	data->top_pixel = (WINDOW_HEIGHT / 2) - (data->strip_height / 2);
	data->bottom_pixel = (WINDOW_HEIGHT / 2) + (data->strip_height / 2);
	if (data->top_pixel < 0)
		data->top_pixel = 0;
	if (data->bottom_pixel >= WINDOW_HEIGHT)
		data->bottom_pixel = WINDOW_HEIGHT - 1;
}

static void	init_texture_coords(t_wall_data *data, t_ray *ray)
{
	if (ray->was_hit_vertical)
		data->tex_x = (int)(ray->wall_hit_y) % TILE_SIZE;
	else
		data->tex_x = (int)(ray->wall_hit_x) % TILE_SIZE;
	data->tex_x = data->tex_x * 64.0f / TILE_SIZE;
	data->step = 64.0f / (float)data->strip_height;
	if (data->strip_height > WINDOW_HEIGHT)
		data->tex_pos = (data->strip_height - WINDOW_HEIGHT) / 2.0f
			* data->step;
	else
		data->tex_pos = 0;
}

static void	draw_wall_slice(t_mlx *mlx, t_wall_data *data, t_ray *ray,
		int ray_index)
{
	int			y;
	int			tex_y;
	t_tex		*texture;
	uint32_t	color;

	texture = &mlx->tex[ray->wall_face];
	init_texture_coords(data, ray);
	y = data->top_pixel;
	while (y < data->bottom_pixel)
	{
		tex_y = (int)data->tex_pos & 63;
		data->tex_pos += data->step;
		color = get_shaded_color(texture, data->perp_distance, (int)data->tex_x,
				tex_y);
		((uint32_t *)mlx->img.addr)[(WINDOW_WIDTH * y) + ray_index] = color;
		y++;
	}
}

void	render_3d_projection_walls(t_mlx *mlx)
{
	int			i;
	t_wall_data	wall;
	t_ray		*ray;

	i = 0;
	while (i < mlx->player.number_of_rays)
	{
		ray = &mlx->player.rays[i];
		init_wall_data(&wall, mlx, ray);
		draw_ceiling(mlx, wall.top_pixel, i);
		draw_wall_slice(mlx, &wall, ray, i);
		draw_floor(mlx, wall.bottom_pixel, i);
		i++;
	}
}
