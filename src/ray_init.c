/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:07:39 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 18:09:04 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
	{
		angle += (2 * M_PI);
	}
	return (angle);
}

void	ray(t_mlx *mlx, t_ray *ray)
{
	ray->ray_angle = normalize_angle(mlx->player.start_column_angle);
	ray->wall_hit_x = 0;
	ray->wall_hit_y = 0;
	ray->distance = 0;
	ray->vertical_distance = 0;
	ray->horizontal_distance = 0;
	ray->is_ray_facing_down = ray->ray_angle > 0 && ray->ray_angle < M_PI;
	ray->is_ray_facing_up = !ray->is_ray_facing_down;
	ray->is_ray_facing_right = ray->ray_angle < 0.5 * M_PI
		|| ray->ray_angle > 1.5 * M_PI;
	ray->is_ray_facing_left = !ray->is_ray_facing_right;
	ray->was_hit_vertical = false;
}

void	ray_init(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->player.number_of_rays)
	{
		ray(mlx, &mlx->player.rays[i]);
		i++;
	}
}
