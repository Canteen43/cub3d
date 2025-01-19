/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_move_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:17:04 by glevin            #+#    #+#             */
/*   Updated: 2025/01/19 21:01:08 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_move_player(t_player *player)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->left_rotate)
		player->angle += ANGLE_SPEED;
	if (player->right_rotate)
		player->angle -= ANGLE_SPEED;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;
	if (player->key_up)
	{
		// player->x += cos_angle * SPEED;
		f_attempt_move(player, 'x', cos_angle * SPEED);
		player->y -= sin_angle * SPEED;
	}
	if (player->key_down)
	{
		player->x -= cos_angle * SPEED;
		player->y += sin_angle * SPEED;
	}
	if (player->key_right)
	{
		player->x += sin_angle * SPEED;
		player->y += cos_angle * SPEED;
	}
	if (player->key_left)
	{
		player->x -= sin_angle * SPEED;
		player->y -= cos_angle * SPEED;
	}
}
