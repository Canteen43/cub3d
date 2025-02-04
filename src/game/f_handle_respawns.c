/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_respawns.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:11:16 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 11:45:15 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_handle_respawns(t_game *game)
{
	t_obs_resp	*obs;
	int			y;
	int			x;

	obs = game->or_head;
	while (obs)
	{
		y = obs->coords.y;
		x = obs->coords.x;
		if (f_distance(game->player_pos, (t_coords){x + 0.5, y + 0.5}) > 5)
		{
			game->map[y][x] = obs->type;
			f_remove_from_respawn_list(game, obs);
		}
		obs = obs->next;
	}
}
