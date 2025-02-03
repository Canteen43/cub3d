/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_remove_obstacle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:47:45 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	f_remove_obstacle(t_game *game)
{
	t_int_xy	tile;
	char		type;

	tile = f_determine_adjacent_tile(game);
	type = game->map[tile.y][tile.x];
	if (type == '1' || type == '0')
	{
		printf("You are not in range.\n");
		return ;
	}
	game->map[tile.y][tile.x] = '0';
	f_add_obstacle_to_respawn_list(game, tile, type);
}
