/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:10:54 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/25 16:19:07 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static float floorf_unless_almost_round(float coord);
bool	f_is_wall(t_game *game, t_coords coords)
{
	char		**map;
	t_int_xy	pos;

	map = game->map;
	pos.x = floorf_unless_almost_round(coords.x);
	pos.y = floorf_unless_almost_round(coords.y);
	if (pos.x < 0 || pos.x >= game->map_line_width || pos.y < 0
		|| pos.y >= game->map_line_count)
		return (false);
	if (map[pos.y][pos.x] != '0')
		return (true);
	if (f_is_round(coords.y) && map[pos.y - 1][pos.x] != '0')
		return (true);
	if (f_is_round(coords.x) && map[pos.y][pos.x - 1] != '0')
		return (true);
	return (false);
}

static	float floorf_unless_almost_round(float coord)
{
	if (f_is_round(coord))
		return (roundf(coord));
	return (floorf(coord));
}
