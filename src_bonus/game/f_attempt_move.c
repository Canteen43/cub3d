/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_attempt_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:50:06 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static bool	sf_wall_touch_with_buffer(t_game *game, t_coords new);

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
	if (sf_wall_touch_with_buffer(game, new))
		return ;
	if (dimension == 'x')
		game->player_pos.x += distance;
	else if (dimension == 'y')
		game->player_pos.y += distance;
	else
		f_graceful_exit(game, 1, __func__, "Wrong dimension.");
}

static bool	sf_wall_touch_with_buffer(t_game *game, t_coords new)
{
	if (game->map[(int)(new.y + WALL_BUFFER)][(int)(new.x
			+ WALL_BUFFER)] != '0')
		return (true);
	if (game->map[(int)(new.y - WALL_BUFFER)][(int)(new.x
			- WALL_BUFFER)] != '0')
		return (true);
	if (game->map[(int)(new.y + WALL_BUFFER)][(int)(new.x
			- WALL_BUFFER)] != '0')
		return (true);
	if (game->map[(int)(new.y - WALL_BUFFER)][(int)(new.x
			+ WALL_BUFFER)] != '0')
		return (true);
	return (false);
}
