/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_distance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:19:51 by glevin            #+#    #+#             */
/*   Updated: 2025/01/18 12:27:06 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	f_distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	f_fixed_dist(float x1, float y1, float x2, float y2, t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = f_distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}
