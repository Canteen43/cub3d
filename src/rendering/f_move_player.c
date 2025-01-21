/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_move_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:17:04 by glevin            #+#    #+#             */
/*   Updated: 2025/01/21 14:47:38 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_move_player(t_game *game)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(game->player_angle);
	sin_angle = sin(game->player_angle);
	if (game->left_rotate)
		game->player_angle += ANGLE_SPEED;
	if (game->right_rotate)
		game->player_angle -= ANGLE_SPEED;
	if (game->key_up)
	{
		f_attempt_move(game, 'x', cos_angle * SPEED);
		f_attempt_move(game, 'y', -sin_angle * SPEED);
	}
	if (game->key_down)
	{
		f_attempt_move(game, 'x', -cos_angle * SPEED);
		f_attempt_move(game, 'y', sin_angle * SPEED);
	}
	if (game->key_right)
	{
		f_attempt_move(game, 'x', sin_angle * SPEED);
		f_attempt_move(game, 'y', cos_angle * SPEED);
	}
	if (game->key_left)
	{
		f_attempt_move(game, 'x', -sin_angle * SPEED);
		f_attempt_move(game, 'y', -cos_angle * SPEED);
	}
}
