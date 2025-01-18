/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:20:24 by glevin            #+#    #+#             */
/*   Updated: 2025/01/18 18:20:11 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_draw_walls(float ray_x, float ray_y, t_player *player, t_game *game,
		int i)
{
	float	dist;
	float	height;
	int		start_y;
	int		end;

	dist = f_distance(ray_x - player->x, ray_y - player->y);
	// dist = f_fixed_dist(player->x, player->y, ray_x, ray_y, game);
	height = (BLOCK / dist) * (WIDTH / 2);
	start_y = (HEIGHT - height) / 2;
	end = start_y + height;
	while (start_y < end)
	{
		f_put_pixel(i, start_y, LIGHT_GRAY, game);
		start_y++;
	}
}
