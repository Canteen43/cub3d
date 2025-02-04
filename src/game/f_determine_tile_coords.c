/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_determine_tile_coords.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:24:16 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_int_xy	f_determine_tile_coords(t_game *game, t_coords grid_hit, t_dir dir)
{
	t_int_xy	coords;

	(void)game;
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
	return (coords);
}
