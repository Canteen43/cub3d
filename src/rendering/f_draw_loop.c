/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:22:18 by glevin            #+#    #+#             */
/*   Updated: 2025/01/20 20:28:57 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	f_draw_loop(t_game *game)
{
	t_player	*player;
	// float		fraction;
	// float		start_x;
	// int			i;

	player = &game->player;
	f_move_player(player);
	f_clear_image(game);
	f_draw_minimap(game);
	player->intersection.x = player->x;
	player->intersection.y = player->y;
	while (!f_is_wall(game, player->intersection))
		player->intersection = f_nearest_intersection(player->intersection, player->angle);
	// fraction = PI / 3 / WIDTH;
	// start_x = player->angle - PI / 6 + PI;
	// i = 0;
	// while (i < WIDTH)
	// {
	// 	f_draw_line(player, game, start_x, i);
	// 	start_x += fraction;
	// 	i++;
	// }
	// f_draw_full_square(player->x / 4, player->y / 4, BLOCK / 8, RED, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	usleep(1000000 / FRAMES_PER_SECOND);
	return (0);
}
