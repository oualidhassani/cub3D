/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:37:05 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 18:43:41 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

static void	copy_texture_data(t_mlx *mlx, t_img *img, int tex_index)
{
	int				x;
	int				y;
	int				src_x;
	int				src_y;
	unsigned int	*ptr;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			src_x = x * img->img_width / 64;
			src_y = y * img->img_height / 64;
			ptr = (unsigned int *)(img->addr + (src_y * img->line_length + src_x
						* (img->bits_per_pixel / 8)));
			mlx->tex[tex_index].texture[y * 64 + x] = *ptr;
			x++;
		}
		y++;
	}
}

static int	allocate_texture_buffer(t_mlx *mlx, t_img *img, int index)
{
	mlx->tex[index].width = 64;
	mlx->tex[index].height = 64;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	mlx->tex[index].texture = (uint32_t *)malloc(sizeof(uint32_t) * 64 * 64);
	if (!mlx->tex[index].texture)
	{
		mlx_destroy_image(mlx->mlx, img->img);
		printf("Failed to allocate memory for texture %d\n", index);
		return (0);
	}
	return (1);
}

static void	load_single_texture(t_mlx *mlx, const char *path, int index)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx->mlx, (char *)path, &img.img_width,
			&img.img_height);
	if (!img.img)
	{
		printf("Failed to load texture: %s\n", path);
		exit(1);
	}
	if (!verify_texture_dimensions(mlx, &img, path))
		exit(1);
	if (!allocate_texture_buffer(mlx, &img, index))
		exit(1);
	copy_texture_data(mlx, &img, index);
	mlx_destroy_image(mlx->mlx, img.img);
}

void	load_texture(t_mlx *mlx)
{
	int			i;
	const char	*texture_paths[4];

	i = 0;
	while (i < 4)
		texture_paths[i++] = NULL;
	init_texture_paths(mlx, texture_paths);
	verify_textures(texture_paths);
	i = 0;
	while (i < 4)
	{
		load_single_texture(mlx, texture_paths[i], i);
		i++;
	}
}
