/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_game_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:22:18 by glevin            #+#    #+#             */
/*   Updated: 2025/02/02 12:53:18 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	f_game_loop(t_game *game)
{
	f_move_player(game);
	f_handle_respawns(game);
	f_clear_image(game);
	f_draw_walls(game);
	f_draw_minimap(game);
	if (game->bonus)
		f_draw_charmander(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	usleep(1000000 / FRAMES_PER_SECOND);
	return (0);
}
