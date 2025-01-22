/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_attempt_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:50:06 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/21 14:41:11 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_attempt_move(t_game *game, char dimension, float distance)
{
	t_coords	new;

	new = game->player_pos;
	if (dimension == 'x')
		new.x += distance;
	else if (dimension == 'y')
		new.y += distance;
	else
		f_graceful_exit(game, 1, __func__, "Wrong dimension.");
	if (game->map[(int)new.y][(int)new.x] == '1')
		return ;
	if (dimension == 'x')
		game->player_pos.x += distance;
	else if (dimension == 'y')
		game->player_pos.y += distance;
	else
		f_graceful_exit(game, 1, __func__, "Wrong dimension.");
}
