/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:40:58 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 18:54:38 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	verify_textures(const char *texture_paths[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!texture_paths[i])
		{
			printf("Error: Missing texture for face %d\n", i);
			exit(1);
		}
		i++;
	}
}

int	verify_texture_dimensions(t_mlx *mlx, t_img *img, const char *path)
{
	if (img->img_width != 64 || img->img_height != 64)
	{
		printf("Warning: Texture %s is not 64x64 (%dx%d)\n", path,
			img->img_width, img->img_height);
		mlx_destroy_image(mlx->mlx, img->img);
		return (0);
	}
	return (1);
}
