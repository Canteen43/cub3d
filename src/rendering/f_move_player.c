/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_move_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:17:04 by glevin            #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	f_move_player(t_game *game)
{
	if (game->left_rotate)
		game->player_angle += ANGLE_SPEED;
	if (game->right_rotate)
		game->player_angle -= ANGLE_SPEED;
	if (game->key_up)
	{
		f_attempt_move(game, 'x', cos(game->player_angle) * SPEED);
		f_attempt_move(game, 'y', -sin(game->player_angle) * SPEED);
	}
	if (game->key_down)
	{
		f_attempt_move(game, 'x', -cos(game->player_angle) * SPEED);
		f_attempt_move(game, 'y', sin(game->player_angle) * SPEED);
	}
	if (game->key_right)
	{
		f_attempt_move(game, 'x', sin(game->player_angle) * SPEED);
		f_attempt_move(game, 'y', cos(game->player_angle) * SPEED);
	}
	if (game->key_left)
	{
		f_attempt_move(game, 'x', -sin(game->player_angle) * SPEED);
		f_attempt_move(game, 'y', -cos(game->player_angle) * SPEED);
	}
}
