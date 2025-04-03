/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_points.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:56:29 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/27 14:50:15 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	init_check_points(float check_points[8][2])
{
	check_points[0][0] = -0.5f;
	check_points[0][1] = -0.5f;
	check_points[1][0] = 0.5f;
	check_points[1][1] = -0.5f;
	check_points[2][0] = 0.5f;
	check_points[2][1] = 0.5f;
	check_points[3][0] = -0.5f;
	check_points[3][1] = 0.5f;
	check_points[4][0] = 0.0f;
	check_points[4][1] = -0.5f;
	check_points[5][0] = 0.0f;
	check_points[5][1] = 0.5f;
	check_points[6][0] = -0.5f;
	check_points[6][1] = 0.0f;
	check_points[7][0] = 0.5f;
	check_points[7][1] = 0.0f;
}
