/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_determine_tile_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:47:54 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/29 18:52:20 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	f_determine_tile_type(t_game *game, t_coords wall_hit, t_dir dir)
{
	int	x;
	int	y;

	if (dir == north || dir == south)
	{
		y = roundf(wall_hit.y);
		x = truncf(wall_hit.x);
	}
	if (dir == west || dir == east)
	{
		y = truncf(wall_hit.y);
		x = roundf(wall_hit.x);
	}
	if (dir == north)
		y--;
	else if (dir == west)
		x--;
	return (game->map[y][x]);
}
