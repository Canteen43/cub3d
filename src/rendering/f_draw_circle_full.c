/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_circle_full.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:38:04 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/19 20:19:46 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_draw_circle_full(t_game *game, t_circle circle)
{
	int	i;
	int	j;

	i = circle.center.x - circle.radius;
	if (i < 0)
		i = 0;
	j = circle.center.y - circle.radius;
	if (i < 0)
		i = 0;
	while (i < circle.center.x + circle.radius)
	{
		j = 0;
		while (j < circle.center.y + circle.radius)
		{
			if (f_distance2(circle.center, (t_coords){i, j}) <= circle.radius)
				f_put_pixel(i, j, circle.color, game);
			j++;
		}
		i++;
	}
}
