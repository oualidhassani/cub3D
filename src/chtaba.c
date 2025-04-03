/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chtaba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:49:36 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 17:49:56 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	cleanup_textures(t_mlx *mlx)
{
	int	i;

	i = 0;
	if (!mlx)
		return ;
	while (i < 4)
	{
		free(mlx->tex[i].texture);
		i++;
	}
}

void	cleanup_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->map)
	{
		while (i < map->height)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

void	cleanup_mlx(t_mlx *mlx)
{
	if (!mlx || !mlx->mlx)
		return ;
	cleanup_textures(mlx);
	if (mlx->img.img)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx->img.img = NULL;
	}
	if (mlx->win)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx->win = NULL;
	}
	free(mlx->mlx);
}
