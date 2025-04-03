/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:32:45 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 18:36:45 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	adjusting_rays(t_mlx *mlx)
{
	int		column;
	float	tmp;

	column = 0;
	mlx->player.start_column_angle = mlx->player.rotation_angle
		- (mlx->player.fov / 2);
	tmp = normalize_angle(mlx->player.start_column_angle);
	mlx->player.start_column_angle = tmp;
	while (column < mlx->player.number_of_rays)
	{
		mlx->player.rays[column].id = column;
		mlx->player.rays[column].ray_angle = mlx->player.start_column_angle;
		ray(mlx, &mlx->player.rays[column]);
		mlx->player.start_column_angle += mlx->player.fov
			/ mlx->player.number_of_rays;
		tmp = normalize_angle(mlx->player.start_column_angle);
		mlx->player.start_column_angle = tmp;
		cast(mlx, &mlx->player.rays[column]);
		column++;
	}
}

void	player_center_position(t_mlx *mlx, int x, int y)
{
	mlx->player.p_x = x * TILE_SIZE + (TILE_SIZE / 2);
	mlx->player.p_y = y * TILE_SIZE + (TILE_SIZE / 2);
}

void	render_all(t_mlx *mlx)
{
	adjusting_rays(mlx);
	render_3d_projection_walls(mlx);
}
