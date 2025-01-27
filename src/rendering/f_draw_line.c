/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:53:25 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/27 10:23:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_draw_line(t_game *game, t_line line)
{
	t_coords	diff_vector;
	int			longer_diff;
	int			i;

	diff_vector.x = line.end.x - line.start.x;
	diff_vector.y = line.end.y - line.start.y;
	longer_diff = fmaxf(fabsf(diff_vector.x), fabsf(diff_vector.y));
	diff_vector.x /= longer_diff;
	diff_vector.y /= longer_diff;
	i = 0;
	while (i < longer_diff)
	{
		f_put_pixel(line.start.x + i * diff_vector.x, line.start.y + i
			* diff_vector.y, line.color, game);
		i++;
	}
}
