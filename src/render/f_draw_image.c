/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:57:34 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_draw_image(t_game *game, t_tex *tex, t_int_xy top_left)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	y = 0;
	while (y < tex->height)
	{
		while (x < tex->width)
		{
			color = f_get_pixel(game, tex, (t_coords){x, y});
			f_put_pixel(top_left.x + x, top_left.y + y, color, game);
			x++;
		}
		y++;
		x = 0;
	}
}
