/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_attempt_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:50:06 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/19 20:59:41 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void f_attempt_move(t_player *player, char dimension, float distance)
{
	t_coords	new;

	new.x = player->x;
	new.y = player->y;
	if (dimension == 'x')
		new.x += distance;
	else if (dimension == 'y')
		new.y += distance;
	else
		f_graceful_exit(player->main, 1, __func__, "Wrong dimension.");
	if (player->main->map[(int)new.x][(int)new.y] == '1')
		return ;
	if (dimension == 'x')
		player->x += distance;
	else if (dimension == 'y')
		player->y += distance;
	else
		f_graceful_exit(player->main, 1, __func__, "Wrong dimension.");
}
