/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:46:43 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 18:54:14 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	reset_movement_flags(t_mlx *mlx)
{
	mlx->player.turn_direction = 0;
	mlx->player.walk_direction = 0;
	mlx->player.strafe_direction = 0;
}

void	update_position(t_mlx *mlx, float move_step, float strafe_step)
{
	mlx->player.p_x += cos(mlx->player.rotation_angle) * move_step
		+ cos(mlx->player.rotation_angle + M_PI / 2) * strafe_step;
	mlx->player.p_y += sin(mlx->player.rotation_angle) * move_step
		+ sin(mlx->player.rotation_angle + M_PI / 2) * strafe_step;
}

void	save_current_position(t_mlx *mlx, int *old_x, int *old_y)
{
	*old_x = mlx->player.p_x;
	*old_y = mlx->player.p_y;
}
