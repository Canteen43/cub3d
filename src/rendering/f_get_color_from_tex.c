/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_color_from_tex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:23:28 by glevin            #+#    #+#             */
/*   Updated: 2025/01/28 18:09:24 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Static functions:
static float	sf_get_fractional(t_coords wall_hit);
static t_tex	*sf_get_direction(t_game *game, t_coords wall_hit);

int	f_get_color_from_tex(t_game *game, t_coords wall_hit, float wall_height_ratio)
{
	int		x_i;
	int		y_i;
	int		offset;
	int		color;
	t_tex	*texture;
	t_dir	direction;

	direction = sf_get_direction(game, wall_hit);
	texture = sf_get_direction(game, wall_hit);
	if (wall_height_ratio < 0)
		wall_height_ratio = 0;
	y_i = (int)(wall_height_ratio * texture->height);
	if (texture->direction == 3 || texture->direction == 4)
		x_i = (1 - sf_get_fractional(wall_hit)) * texture->width;
	else
		x_i = sf_get_fractional(wall_hit) * texture->width;
	offset = y_i * texture->size_line + (x_i * (texture->bpp / 8));
	color = *(int *)((char *)texture->data + offset);
	return (color);
}

static t_dir	*sf_get_direction(t_game *game, t_coords wall_hit)
{
	if (modff(wall_hit.x, NULL) == 0)
	{
		if (game->player_pos.x > wall_hit.x)
			return (west);
		else
			return (east);
	}
	else
	{
		if (game->player_pos.y > wall_hit.y)
			return (north);
		else
			return (south);
	}
}

static float	sf_get_fractional(t_coords wall_hit)
{
	float	fractional_x;
	float	fractional_y;
	int		x;
	int		y;

	x = wall_hit.x;
	y = wall_hit.y;
	fractional_x = wall_hit.x - x;
	fractional_y = wall_hit.y - y;
	if (fractional_x > fractional_y)
		return (fractional_x);
	return (fractional_y);
}
