/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:13:52 by glevin            #+#    #+#             */
/*   Updated: 2025/02/03 13:51:20 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	f_get_pixel(t_game *game, t_tex *tex, t_coords pos)
{
	int	offset;
	int	color;
	int	x;
	int	y;

	x = pos.x * tex->width;
	if (x < 0)
		x = 0;
	if (x >= tex->width)
		x = tex->width - 1;
	y = pos.y * tex->height;
	if (y < 0)
		y = 0;
	if (y >= tex->width)
		y = tex->height - 1;
	(void)game;
	offset = y * tex->size_line + (x * (tex->bpp / 8));
	color = *(int *)((char *)tex->data + offset);
	return (color);
}
