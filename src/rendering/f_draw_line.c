/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:21:24 by glevin            #+#    #+#             */
/*   Updated: 2025/01/19 18:01:25 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_draw_line(t_player *player, t_game *game, float start_x, int i)
{
	float	ray_x;
	float	ray_y;
	float	cos_angle;
	float	sin_angle;
	// bool	touch;

	ray_x = player->x;
	ray_y = player->y;
	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	// touch = false;
	while (!f_touch(ray_x, ray_y, game))
	{
		f_put_pixel(ray_x, ray_y, PINK, game);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	f_draw_walls(ray_x, ray_y, player, game, i);
}
