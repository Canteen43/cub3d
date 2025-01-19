/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:31:38 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/19 20:25:26 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_draw_minimap(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	f_draw_full_square(0, 0, game->main->map_line_count *MINIBLOCK, YELLOW, game);
	while (game->main->map[++y])
	{
		x = -1;
		while (game->main->map[y][++x])
		{
			if (game->main->map[x][y] == '1')
			{
				f_draw_square(x * MINIBLOCK, y * MINIBLOCK, MINIBLOCK, BLUE,
					game);
			}
		}
	}
	f_draw_circle_full(game, (t_circle){RED, MINIBLOCK / 3, (t_coords){game->player.x * MINIBLOCK, game->player.y * MINIBLOCK}});
	f_draw_circle_full(game, (t_circle){PINK, MINIBLOCK / 5, (t_coords){(game->player.x + 0.3 * cos(game->player.angle)) * MINIBLOCK, (game->player.y - 0.3 * sin(game->player.angle)) * MINIBLOCK}});
}
