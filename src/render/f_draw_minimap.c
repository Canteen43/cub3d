/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:31:38 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/26 11:54:40 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

// Static functions:
static t_coords	sf_get_coords(t_game *game, t_int_xy pixel);

void	f_draw_minimap(t_game *game)
{
	t_int_xy	pixel;
	int			color;
	t_coords	coords;

	pixel.y = 0;
	while (pixel.y < MINI_HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < MINI_HEIGHT)
		{
			coords = sf_get_coords(game, pixel);
			if (f_is_wall(game, coords))
				color = DARK_GRAY;
			else if (f_is_visible(game, coords))
				color = ORANGE;
			else
				color = LIGHT_GRAY;
			f_put_pixel(pixel.x, pixel.y, color, game);
			pixel.x++;
		}
		pixel.y++;
	}

}

static t_coords	sf_get_coords(t_game *game, t_int_xy pixel)
{
	t_coords	coords;

	coords.x = game->player_pos.x - DISTANCE_SEEN + ((float)pixel.x
			/ MINI_HEIGHT * DISTANCE_SEEN * 2);
	coords.y = game->player_pos.y - DISTANCE_SEEN + ((float)pixel.y
			/ MINI_HEIGHT * DISTANCE_SEEN * 2);
	return (coords);
}

