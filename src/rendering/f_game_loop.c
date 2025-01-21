/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_game_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:22:18 by glevin            #+#    #+#             */
/*   Updated: 2025/01/21 15:35:41 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	f_game_loop(t_game *game)
{
	f_move_player(game);
	f_clear_image(game);
	f_draw_minimap(game);
	game->grid_hit = f_next_grid_hit(game->player_pos, game->player_angle);
	game->wall_hit = game->grid_hit;
	while (!f_is_wall(game, game->wall_hit))
		game->wall_hit = f_next_grid_hit(game->wall_hit, game->player_angle);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	usleep(1000000 / FRAMES_PER_SECOND);
	return (0);
}
