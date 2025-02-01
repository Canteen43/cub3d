/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_remove_from_respawn_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:04:45 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/01 20:29:58 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_remove_from_respawn_list(t_game *game, t_obstacle_respawn *obs)
{
	if (obs == game->or_head)
		game->or_head = obs->prev;
	if (obs->prev)
		obs->prev->next = obs->next;
	if (obs->next)
		obs->next->prev = obs->prev;
}
