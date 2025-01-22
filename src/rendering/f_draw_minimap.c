/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:31:38 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/21 16:11:47 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_draw_minimap(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	f_draw_full_square(game, (t_square){YELLOW, game->map_line_count
		* MINIBLOCK, (t_coords){0, 0}});
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
			{
				f_draw_square(game, (t_square){BLUE, MINIBLOCK,
					(t_coords){x * MINIBLOCK, y * MINIBLOCK}});
			}
		}
	}
	f_draw_circle_full(game, (t_circle){RED, MINIBLOCK / 3,
		(t_coords){game->player_pos.x * MINIBLOCK, game->player_pos.y
		* MINIBLOCK}});
	f_draw_circle_full(game, (t_circle){PINK, MINIBLOCK / 5,
		(t_coords){(game->player_pos.x + 0.3 * cos(game->player_angle))
		* MINIBLOCK, (game->player_pos.y - 0.3 * sin(game->player_angle))
		* MINIBLOCK}});
}
