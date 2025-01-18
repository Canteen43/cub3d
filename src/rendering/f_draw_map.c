/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:18:37 by glevin            #+#    #+#             */
/*   Updated: 2025/01/18 12:18:42 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_draw_map(t_game *game)
{
	int	color;
	int	y;
	int	x;

	color = 0x0000FF;
	y = -1;
	while (game->main->map[++y])
	{
		x = -1;
		while (game->main->map[y][++x])
		{
			if (game->main->map[x][y] == '1')
			{
				f_draw_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
			}
		}
	}
}
