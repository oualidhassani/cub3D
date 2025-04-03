/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:15:59 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/27 14:50:40 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	draw_ceiling(t_mlx *mlx, int top_pixel, int ray_index)
{
	int	y;

	y = 0;
	while (y < top_pixel)
	{
		((uint32_t *)mlx->img.addr)[(WINDOW_WIDTH * y)
			+ ray_index] = (mlx->maps.ceiling_rgb.r << 16)
			| (mlx->maps.ceiling_rgb.g << 8)
			| mlx->maps.ceiling_rgb.b;
		y++;
	}
}
