/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fish_eye_correction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:50:46 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/19 17:53:49 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

float	calculate_perp_distance(t_ray *ray, float player_angle)
{
	float	perp_distance;

	perp_distance = ray->distance * cos(ray->ray_angle - player_angle);
	if (perp_distance > 0.001f)
		return (perp_distance);
	else
		return (0.001f);
}
