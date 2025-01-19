/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:11:40 by glevin            #+#    #+#             */
/*   Updated: 2025/01/19 18:45:12 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_init_player(t_game *game, t_player *player)
{
	player->main = game->main;
	player->x = game->main->player_x;
	player->y = game->main->player_y;
	if (game->main->direction == 'E')
		player->angle = PI * 0;
	if (game->main->direction == 'N')
		player->angle = PI * 0.5;
	if (game->main->direction == 'W')
		player->angle = PI * 1.0;
	if (game->main->direction == 'S')
		player->angle = PI * 1.5;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}
