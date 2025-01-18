/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:22:18 by glevin            #+#    #+#             */
/*   Updated: 2025/01/18 13:54:21 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	f_draw_loop(t_game *game)
{
	t_player *player;
	float fraction;
	float start_x;
	int i;

	player = &game->player;
	f_move_player(player);
	f_clear_image(game);
	fraction = PI / 3 / WIDTH;
	start_x = player->angle - PI / 6 + PI;
	i = 0;
	while (i < WIDTH)
	{
		f_draw_line(player, game, start_x, i);
		start_x += fraction;
		i++;
	}
	f_draw_map(game);
	f_draw_square(player->x, player->y, 8, 0x00FF00, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	// usleep(10000); // To lower the fps and reduce expense to the CPU
	return (0);
}
