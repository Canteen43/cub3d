/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:13:52 by glevin            #+#    #+#             */
/*   Updated: 2025/02/03 13:25:48 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	f_get_pixel(t_game *game, t_tex *tex, t_coords pos)
{
	int	offset;
	int	color;

	(void)game;
	offset = (int)pos.y * tex->size_line + ((int)pos.x * (tex->bpp / 8));
	color = *(int *)((char *)tex->data + offset);
	return (color);
}
