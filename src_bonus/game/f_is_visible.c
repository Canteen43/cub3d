/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_visible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:37:20 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/25 17:14:24 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

bool	f_is_visible(t_game *game, t_coords coords)
{
	t_coords	vector;
	float		angle;
	t_coords	wallhit;

	vector.x = coords.x - game->player_pos.x;
	vector.y = coords.y - game->player_pos.y;
	angle = atan2f(-vector.y, vector.x);
	if (f_angle_diff(angle, game->player_angle) > FOV / 2)
		return (false);
	wallhit = f_next_wall_hit(game, game->player_pos, angle);
	if (f_distance(game->player_pos, coords) > f_distance(game->player_pos,
			wallhit))
		return (false);
	return (true);
}
