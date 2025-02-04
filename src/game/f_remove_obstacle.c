/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_remove_obstacle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:47:45 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 18:12:47 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_remove_obstacle(t_game *game)
{
	t_int_xy	tile;
	t_coords	wall_hit;
	t_dir		dir;
	char		type;

	wall_hit = f_next_wall_hit(game, game->player_pos, game->player_angle);
	if (f_distance(wall_hit, game->player_pos) > ATTACK_DISTANCE)
		return ;
	dir = f_determine_direction(game, wall_hit);
	tile = f_determine_tile_coords(game, wall_hit, dir);
	type = game->map[tile.y][tile.x];
	f_add_to_anim_queue(game, tile, &game->cut);
	f_add_obstacle_to_respawn_list(game, tile, type);
}
