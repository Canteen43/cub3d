/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_game_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:22:18 by glevin            #+#    #+#             */
/*   Updated: 2025/02/25 14:22:50 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	f_game_loop(t_game *game)
{
	f_move_player(game);
	f_handle_respawns(game);
	f_clear_image(game);
	f_draw_walls(game);
	f_draw_minimap(game);
	if (game->bonus && game->pokeball)
		f_draw_charmander(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	f_check_game_end(game);
	usleep(1000000 / FRAMES_PER_SECOND);
	return (0);
}
