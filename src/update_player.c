/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:44:40 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/27 14:46:38 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

int	check_wall_collision(t_mlx *mlx, float check_x, float check_y)
{
	int	grid_x;
	int	grid_y;

	grid_x = floor(check_x / TILE_SIZE);
	grid_y = floor(check_y / TILE_SIZE);
	if (grid_x < 0 || grid_x >= mlx->maps.width || grid_y < 0
		|| grid_y >= mlx->maps.height)
		return (1);
	if (mlx->maps.map[grid_y][grid_x] == '1')
		return (1);
	return (0);
}

int	does_hit_wall(t_mlx *mlx, float x, float y)
{
	int		i;
	float	check_x;
	float	check_y;
	float	check_points[8][2];

	init_check_points(check_points);
	i = 0;
	while (i < 8)
	{
		check_x = x + (check_points[i][0] * mlx->player.size);
		check_y = y + (check_points[i][1] * mlx->player.size);
		if (check_wall_collision(mlx, check_x, check_y))
			return (1);
		i++;
	}
	return (0);
}

void	update_player_position(t_mlx *mlx, float move_step, float strafe_step)
{
	float	new_x;
	float	new_y;

	new_x = mlx->player.p_x + cos(mlx->player.rotation_angle) * move_step
		+ cos(mlx->player.rotation_angle + M_PI / 2) * strafe_step;
	new_y = mlx->player.p_y;
	if (!does_hit_wall(mlx, new_x, new_y))
		mlx->player.p_x = new_x;
	new_x = mlx->player.p_x;
	new_y = mlx->player.p_y + sin(mlx->player.rotation_angle) * move_step
		+ sin(mlx->player.rotation_angle + M_PI / 2) * strafe_step;
	if (!does_hit_wall(mlx, new_x, new_y))
		mlx->player.p_y = new_y;
}

void	update_player(t_mlx *mlx)
{
	float	move_step;
	float	strafe_step;
	float	tmp_walk_direction;
	float	tmp_strafe_direction;
	float	tmp_turn_direction;

	tmp_walk_direction = mlx->player.walk_direction;
	tmp_strafe_direction = mlx->player.strafe_direction;
	tmp_turn_direction = mlx->player.turn_direction;
	reset_movement_flags(mlx);
	mlx->player.rotation_angle += tmp_turn_direction
		* mlx->player.rotation_speed;
	move_step = tmp_walk_direction * mlx->player.move_speed;
	strafe_step = tmp_strafe_direction * mlx->player.move_speed;
	update_player_position(mlx, move_step, strafe_step);
}
