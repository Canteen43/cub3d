/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_move_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:17:04 by glevin            #+#    #+#             */
/*   Updated: 2025/01/20 10:22:40 by kweihman         ###   ########.fr       */
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
	if (player->key_up)
	{
		f_attempt_move(player, 'x', cos_angle * SPEED);
		f_attempt_move(player, 'y', -sin_angle * SPEED);
	}
	if (player->key_down)
	{
		f_attempt_move(player, 'x', -cos_angle * SPEED);
		f_attempt_move(player, 'y', sin_angle * SPEED);
	}
	if (player->key_right)
	{
		f_attempt_move(player, 'x', sin_angle * SPEED);
		f_attempt_move(player, 'y', cos_angle * SPEED);
	}
	if (player->key_left)
	{
		f_attempt_move(player, 'x', -sin_angle * SPEED);
		f_attempt_move(player, 'y', -cos_angle * SPEED);
	}
}
