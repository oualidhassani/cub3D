/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:02:11 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 18:02:59 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

static void	handle_movement_keys(t_mlx *mlx, int key_code)
{
	if (key_code == 65361)
	{
		mlx->player.turn_direction = -1;
		refreshing(mlx);
	}
	else if (key_code == 65363)
	{
		mlx->player.turn_direction = 1;
		refreshing(mlx);
	}
	else if (key_code == 119 || key_code == 65362)
	{
		mlx->player.walk_direction = 1;
		refreshing(mlx);
	}
	else if (key_code == 115 || key_code == 65364)
	{
		mlx->player.walk_direction = -1;
		refreshing(mlx);
	}
}

static void	handle_strafe_keys(t_mlx *mlx, int key_code)
{
	if (key_code == 97)
	{
		mlx->player.strafe_direction = -1;
		refreshing(mlx);
	}
	else if (key_code == 100)
	{
		mlx->player.strafe_direction = 1;
		refreshing(mlx);
	}
}

int	key_press(int key_code, void *mlx_ptr)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)mlx_ptr;
	if (key_code == 65307)
	{
		free(mlx->player.rays);
		handle_exit(mlx);
		exit(0);
	}
	handle_movement_keys(mlx, key_code);
	handle_strafe_keys(mlx, key_code);
	return (0);
}

int	key_release(int key_code, void *mlx_ptr)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)mlx_ptr;
	if (key_code == 65307)
	{
		exit(0);
	}
	else if (key_code == 119)
		mlx->player.walk_direction = 0;
	else if (key_code == 115)
		mlx->player.walk_direction = 0;
	else if (key_code == 97)
		mlx->player.turn_direction = 0;
	else if (key_code == 100)
		mlx->player.turn_direction = 0;
	return (0);
}
