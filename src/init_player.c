/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:54:20 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 17:56:56 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	set_starting_direction(t_mlx *mlx)
{
	char	direction;

	direction = mlx->player.starting_face_in_map;
	if (direction == 'N')
		mlx->player.rotation_angle = 3 * M_PI / 2;
	else if (direction == 'S')
		mlx->player.rotation_angle = M_PI / 2;
	else if (direction == 'E')
		mlx->player.rotation_angle = 0;
	else if (direction == 'W')
		mlx->player.rotation_angle = M_PI;
}

void	init_player(t_mlx *mlx)
{
	player_position(mlx);
	mlx->player.strafe_direction = 0;
	mlx->player.size = 4;
	mlx->player.turn_direction = 0;
	mlx->player.walk_direction = 0;
	set_starting_direction(mlx);
	mlx->player.move_speed = 10.0 * (TILE_SIZE / 64.0);
	mlx->player.rotation_speed = 2 * (M_PI / 180);
	mlx->player.fov = 60 * (M_PI / 180);
	mlx->player.wall_strip_width = 1;
	mlx->player.number_of_rays = WINDOW_WIDTH / mlx->player.wall_strip_width;
	mlx->player.rays = malloc(sizeof(t_ray) * mlx->player.number_of_rays);
	if (!mlx->player.rays)
		exit(1);
	mlx->player.start_column_angle = 0;
	ray_init(mlx);
}

int	does_hit_right_bottom_wall(t_mlx *mlx, int x, int y)
{
	int	right_x;
	int	bottom_y;
	int	converting_x_to_grid;
	int	converting_y_to_grid;

	right_x = x + (mlx->player.size / 2);
	bottom_y = y + (mlx->player.size / 2);
	converting_x_to_grid = floor(right_x / TILE_SIZE);
	converting_y_to_grid = floor(bottom_y / TILE_SIZE);
	if (mlx->maps.map[converting_y_to_grid][converting_x_to_grid] == '1')
		return (1);
	return (0);
}

int	does_hit_left_top_wall(t_mlx *mlx, int x, int y)
{
	int	left_x;
	int	top_y;
	int	converting_x_to_grid;
	int	converting_y_to_grid;

	left_x = x + (mlx->player.size / -2);
	top_y = y + (mlx->player.size / -2);
	converting_x_to_grid = floor(left_x / TILE_SIZE);
	converting_y_to_grid = floor(top_y / TILE_SIZE);
	if (mlx->maps.map[converting_y_to_grid][converting_x_to_grid] == '1')
	{
		return (1);
	}
	return (0);
}
