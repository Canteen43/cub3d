/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_line copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:53:25 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/22 18:18:33 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_draw_line_mapsafe(t_game *game, t_line line)
{
	t_coords	diff_vector;
	int			longer_diff;
	int			i;
	t_int_xy	pixel;

	diff_vector.x = line.end.x - line.start.x;
	diff_vector.y = line.end.y - line.start.y;
	longer_diff = fmaxf(fabsf(diff_vector.x), fabsf(diff_vector.y));
	diff_vector.x /= longer_diff;
	diff_vector.y /= longer_diff;
	i = 0;
	while (i < longer_diff)
	{
		pixel.x = line.start.x + i * diff_vector.x;
		pixel.y = line.start.y + i * diff_vector.y;
		if (pixel.x < 0 || pixel.y < 0 || pixel.x > MINI_HEIGHT || pixel.y > MINI_HEIGHT)
			return ;
		f_put_pixel(pixel.x, pixel.y, line.color, game);
		i++;
	}
}
