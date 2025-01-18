/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:31:38 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/18 18:13:04 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_draw_minimap(t_game *game)
{
	int	y;
	int	x;
	int	mini_block;

	mini_block = BLOCK / 4;
	y = -1;
	f_draw_full_square(0, 0, game->main->map_line_count * mini_block, YELLOW, game);
	while (game->main->map[++y])
	{
		x = -1;
		while (game->main->map[y][++x])
		{
			if (game->main->map[x][y] == '1')
			{
				f_draw_square(x * mini_block, y * mini_block, mini_block, BLUE,
					game);
			}
		}
	}
}
