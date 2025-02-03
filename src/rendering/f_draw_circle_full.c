/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_circle_full.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:38:04 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

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
			if (f_distance(circle.center, (t_coords){i, j}) <= circle.radius)
				f_put_pixel(i, j, circle.color, game);
			j++;
		}
		i++;
	}
}
