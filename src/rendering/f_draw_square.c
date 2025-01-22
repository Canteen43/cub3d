/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:14:25 by glevin            #+#    #+#             */
/*   Updated: 2025/01/21 16:08:22 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_draw_square(t_game *game, t_square sq)
{
	int	i;

	i = -1;
	while (sq.size > ++i)
		f_put_pixel(sq.top_left.x + i, sq.top_left.y, sq.color, game);
	i = -1;
	while (sq.size > ++i)
		f_put_pixel(sq.top_left.x, sq.top_left.y + i, sq.color, game);
	i = -1;
	while (sq.size > ++i)
		f_put_pixel(sq.top_left.x + sq.size, sq.top_left.y + i, sq.color, game);
	i = -1;
	while (sq.size > ++i)
		f_put_pixel(sq.top_left.x + i, sq.top_left.y + sq.size, sq.color, game);
}
