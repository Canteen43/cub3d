/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_from_tex_to_area.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:40:04 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_draw_from_tex_to_area(t_game *game, t_tex *tex, t_rect area)
{
	int		x;
	int		y;
	int		color;
	float	tex_x;
	float	tex_y;

	x = 0;
	y = 0;
	while (y < area.height)
	{
		while (x < area.width)
		{
			tex_x = (float)x / area.width;
			tex_y = (float)y / area.height;
			color = f_get_pixel(game, tex, (t_coords){tex_x, tex_y});
			f_put_pixel(area.top_left.x + x, area.top_left.y + y, color, game);
			x++;
		}
		y++;
		x = 0;
	}
}
