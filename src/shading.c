/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:26:07 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 18:32:22 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

uint32_t	apply_shade(uint32_t color, float shade)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	r = ((color >> 16) & 0xFF) * shade;
	g = ((color >> 8) & 0xFF) * shade;
	b = (color & 0xFF) * shade;
	return ((r << 16) | (g << 8) | b);
}

uint32_t	get_shaded_color(t_tex *texture, float perp_distance, int tex_x,
		int tex_y)
{
	uint32_t	color;
	float		shade;

	color = texture->texture[64 * tex_y + (tex_x & 63)];
	shade = fmax(0.3f, 1.0f - (perp_distance / (WINDOW_WIDTH * 0.8f)));
	return (apply_shade(color, shade));
}
