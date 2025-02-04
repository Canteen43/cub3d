/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add_obstacle_to_respawn_list.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:58:02 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 10:43:54 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_add_obstacle_to_respawn_list(t_game *game, t_int_xy coords, char type)
{
	t_obs_resp	*obs;
	t_obs_resp	*last;

	obs = f_gc_malloc(game, sizeof(t_obs_resp));
	obs->coords = coords;
	obs->type = type;
	obs->next = NULL;
	if (!game->or_head)
	{
		game->or_head = obs;
		obs->prev = NULL;
		return ;
	}
	last = game->or_head;
	while (last->next)
		last = last->next;
	last->next = obs;
	obs->prev = last;
}
