/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_determine_adjacent_tile.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:54:38 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/01 19:34:27 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_int_xy	f_determine_adjacent_tile(t_game *game)
{
	t_coords	grid_hit;
	t_dir		dir;
	t_int_xy	tile_coords;

	grid_hit = f_next_grid_hit(game->player_pos, game->player_angle);
	dir = f_determine_direction(game, grid_hit);
	tile_coords = f_determine_tile_coords(game, grid_hit, dir);
	return (tile_coords);
}
