/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:31:38 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/25 13:40:17 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

// Static functions:
static t_coords	sf_get_coords(t_game *game, t_int_xy pixel);
static void		sf_draw_pokeball(t_game *game);

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
	if (game->bonus)
		sf_draw_pokeball(game);
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

static void	sf_draw_pokeball(t_game *game)
{
	t_rect	area;

	area.width = game->bonus_pokeball_minimap.width / 2;
	area.top_left.x = MINI_HEIGHT / 2 - area.width / 2;
	area.height = game->bonus_pokeball_minimap.height / 2;
	area.top_left.y = MINI_HEIGHT / 2 - area.height / 2;
	f_draw_from_tex_to_area(game, &game->bonus_pokeball_minimap, area);
}
