/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refreshing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:08:40 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 18:09:42 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	refreshing(t_mlx *mlx)
{
	update_player(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_scene(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	mlx->player.turn_direction = 0;
	mlx->player.walk_direction = 0;
}
