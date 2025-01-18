/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:14:25 by glevin            #+#    #+#             */
/*   Updated: 2025/01/18 12:14:39 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_draw_square(int x, int y, int size, int color, t_game *game)
{
	int	i;

	i = -1;
	while (size > ++i)
		f_put_pixel(x + i, y, color, game);
	i = -1;
	while (size > ++i)
		f_put_pixel(x, y + i, color, game);
	i = -1;
	while (size > ++i)
		f_put_pixel(x + size, y + i, color, game);
	i = -1;
	while (size > ++i)
		f_put_pixel(x + i, y + size, color, game);
}
