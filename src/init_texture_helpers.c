/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:57:20 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 17:57:21 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	init_texture_paths(t_mlx *mlx, const char *texture_paths[4])
{
	if (mlx->maps.no_texture)
		texture_paths[NORTH_FACE] = mlx->maps.no_texture;
	if (mlx->maps.so_texture)
		texture_paths[SOUTH_FACE] = mlx->maps.so_texture;
	if (mlx->maps.ea_texture)
		texture_paths[EAST_FACE] = mlx->maps.ea_texture;
	if (mlx->maps.we_texture)
		texture_paths[WEST_FACE] = mlx->maps.we_texture;
}

void	free_textures(t_map *map, t_mlx *mlx)
{
	if (map->no_texture)
		mlx_destroy_image(mlx->mlx, map->no_texture);
	if (map->so_texture)
		mlx_destroy_image(mlx->mlx, map->so_texture);
	if (map->we_texture)
		mlx_destroy_image(mlx->mlx, map->we_texture);
	if (map->ea_texture)
		mlx_destroy_image(mlx->mlx, map->ea_texture);
}
