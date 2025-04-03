/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:03:17 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 18:06:03 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	player_position(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mlx->maps.height)
	{
		j = 0;
		while (mlx->maps.map[i][j])
		{
			if (mlx->maps.map[i][j] == 'N' || mlx->maps.map[i][j] == 'S'
				|| mlx->maps.map[i][j] == 'E' || mlx->maps.map[i][j] == 'W')
			{
				mlx->player.starting_face_in_map = mlx->maps.map[i][j];
				player_center_position(mlx, j, i);
				break ;
			}
			j++;
		}
		i++;
	}
}
