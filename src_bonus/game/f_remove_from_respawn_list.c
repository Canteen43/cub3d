/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_remove_from_respawn_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:04:45 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 10:43:54 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_remove_from_respawn_list(t_game *game, t_obs_resp *obs)
{
	if (obs == game->or_head)
		game->or_head = obs->next;
	if (obs->prev)
		obs->prev->next = obs->next;
	if (obs->next)
		obs->next->prev = obs->prev;
}
