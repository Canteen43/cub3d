/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:20:24 by glevin            #+#    #+#             */
/*   Updated: 2025/01/18 12:20:30 by glevin           ###   ########.fr       */
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
		f_put_pixel(i, start_y, 255, game);
		start_y++;
	}
}
