/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_determine_tile_coords.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:24:16 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/25 17:10:08 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_int_xy	f_determine_tile_coords(t_game *game, t_coords grid_hit, t_dir dir)
{
	t_int_xy	coords;

	if (dir == north || dir == south)
	{
		coords.y = roundf(grid_hit.y);
		coords.x = truncf(grid_hit.x);
	}
	if (dir == west || dir == east)
	{
		coords.y = truncf(grid_hit.y);
		coords.x = roundf(grid_hit.x);
	}
	if (dir == north)
		coords.y--;
	else if (dir == west)
		coords.x--;
	if (coords.y >= game->map_line_count)
		coords.y = game->map_line_count - 1;
	return (coords);
}
