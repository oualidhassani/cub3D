/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:06:49 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 17:47:19 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

static void	calculate_vertical_hit(t_ray *ray, t_mlx *mlx, t_ray_calc *calc)
{
	ray->distance = (calc->map_x - calc->pos_x + (1 - calc->step_x) / 2)
		/ calc->ray_dir_x;
	ray->wall_hit_x = mlx->player.p_x + ray->distance * TILE_SIZE
		* calc->ray_dir_x;
	ray->wall_hit_y = mlx->player.p_y + ray->distance * TILE_SIZE
		* calc->ray_dir_y;
	ray->was_hit_vertical = true;
	if (calc->step_x > 0)
		ray->wall_face = EAST_FACE;
	else
		ray->wall_face = WEST_FACE;
}

static void	calculate_horizontal_hit(t_ray *ray, t_mlx *mlx, t_ray_calc *calc)
{
	ray->distance = (calc->map_y - calc->pos_y + (1 - calc->step_y) / 2)
		/ calc->ray_dir_y;
	ray->wall_hit_x = mlx->player.p_x + ray->distance * TILE_SIZE
		* calc->ray_dir_x;
	ray->wall_hit_y = mlx->player.p_y + ray->distance * TILE_SIZE
		* calc->ray_dir_y;
	ray->was_hit_vertical = false;
	if (calc->step_y > 0)
		ray->wall_face = SOUTH_FACE;
	else
		ray->wall_face = NORTH_FACE;
}

static void	calculate_hit_position(t_ray *ray, t_mlx *mlx, t_ray_calc *calc,
		int side)
{
	if (side == 0)
		calculate_vertical_hit(ray, mlx, calc);
	else
		calculate_horizontal_hit(ray, mlx, calc);
	ray->distance *= TILE_SIZE;
}

static int	perform_dda(t_mlx *mlx, t_ray_calc *calc, int *side)
{
	while (1)
	{
		if (calc->side_dist_x < calc->side_dist_y)
		{
			calc->side_dist_x += calc->delta_dist_x;
			calc->map_x += calc->step_x;
			*side = 0;
		}
		else
		{
			calc->side_dist_y += calc->delta_dist_y;
			calc->map_y += calc->step_y;
			*side = 1;
		}
		if (calc->map_x < 0 || calc->map_y < 0 || calc->map_x >= mlx->maps.width
			|| calc->map_y >= mlx->maps.height)
			return (0);
		if (mlx->maps.map[calc->map_y][calc->map_x] == '1')
			return (1);
	}
}

void	cast(t_mlx *mlx, t_ray *ray)
{
	t_ray_calc	calc;
	int			side;

	calc.ray_dir_x = cos(ray->ray_angle);
	calc.ray_dir_y = sin(ray->ray_angle);
	calc.pos_x = mlx->player.p_x / TILE_SIZE;
	calc.pos_y = mlx->player.p_y / TILE_SIZE;
	calc.map_x = (int)calc.pos_x;
	calc.map_y = (int)calc.pos_y;
	calc.delta_dist_x = fabs(1.0f / calc.ray_dir_x);
	calc.delta_dist_y = fabs(1.0f / calc.ray_dir_y);
	init_ray_steps(calc.pos_x, calc.pos_y, &calc);
	if (!perform_dda(mlx, &calc, &side))
	{
		ray->distance = FLT_MAX;
		return ;
	}
	calculate_hit_position(ray, mlx, &calc, side);
}
