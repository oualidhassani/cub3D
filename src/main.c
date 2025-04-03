/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:55:31 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/27 14:40:04 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mlx_initializer(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "CUBED");
	mlx->img.img = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	return (1);
}

void	draw_scene(t_mlx *mlx)
{
	render_all(mlx);
}

int	map_filter(t_map *maps)
{
	int	x;

	x = ft_strlen(maps->map[maps->height - 1]) - 1;
	if (x < (int)ft_strlen(maps->map[maps->height - 2]) - 1)
	{
		x++;
		while (maps->map[maps->height - 2][x] != '\0')
		{
			if (maps->map[maps->height - 2][x] != '1')
				error_print("Map Error ", maps);
			x++;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_map	maps;
	t_mlx	mlx;

	(void)ac;
	start_parsing(av[1], &maps);
	map_filter(&maps);
	if (!mlx_initializer(&mlx))
	{
		error_print("MLX error ", &maps);
		return (0);
	}
	mlx.maps = maps;
	load_texture(&mlx);
	init_player(&mlx);
	draw_scene(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, 02, 1L << 0, key_press, &mlx);
	mlx_hook(mlx.win, 3, 1L << 1, key_release, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
	handle_exit(&mlx);
	return (0);
}
