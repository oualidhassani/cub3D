/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:14:58 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/27 14:51:02 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	draw_floor(t_mlx *mlx, int bottom_pixel, int ray_index)
{
	int	y;

	y = bottom_pixel;
	while (y < WINDOW_HEIGHT)
	{
		((uint32_t *)mlx->img.addr)[(WINDOW_WIDTH * y)
			+ ray_index] = (mlx->maps.floor_rgb.r << 16)
			| (mlx->maps.floor_rgb.g << 8)
			| mlx->maps.floor_rgb.b;
		y++;
	}
}
