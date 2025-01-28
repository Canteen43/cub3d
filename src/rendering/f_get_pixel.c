/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:13:52 by glevin            #+#    #+#             */
/*   Updated: 2025/01/28 15:41:36 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	f_get_pixel(t_game *game, t_tex *tex, int x, int y)
{
	char	*pixel;
	int		color;

	if (x >= tex->width || y >= tex->height || x < 0 || y < 0)
		return (0);
	pixel = game->data + (y * game->size_line) + (x * (game->bpp / 8));
	color = *(unsigned int *)pixel;
	color = 0;
	color += pixel[0];
	color += pixel[1] * 256;
	color += pixel[2] * 256 * 256;
	return (color);
}
