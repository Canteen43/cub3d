/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:23:28 by glevin            #+#    #+#             */
/*   Updated: 2025/01/25 13:29:08 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Static functions:
static float	sf_get_fractional(t_coords wall_hit);
static t_tex	*sf_get_texture_map(t_game *game, t_coords wall_hit);

int	f_get_texture(int y, t_game *game, int wall_height, t_coords wall_hit)
{
	int		x_i;
	int		y_i;
	int		offset;
	int		color;
	float	wall_height_ratio;
	int		ceiling_height;
	t_tex	*texture;

	ceiling_height = HEIGHT / 2 - wall_height / 2 + 1;
	wall_height_ratio = (y - ceiling_height) / (float)wall_height;
	texture = sf_get_texture_map(game, wall_hit);
	y_i = (int)(wall_height_ratio * (float)texture->height);
	x_i = sf_get_fractional(wall_hit) * texture->width;
	offset = y_i * texture->size_line + (x_i * (texture->bpp / 8));
	color = *(int *)((char *)texture->data + offset);
	return (color);
}

static t_tex	*sf_get_texture_map(t_game *game, t_coords wall_hit)
{
	float	x_fractional;
	float	y_fractional;

	x_fractional = wall_hit.x - (int)wall_hit.x;
	y_fractional = wall_hit.y - (int)wall_hit.y;
	if (x_fractional == 0)
	{
		if (game->player_pos.x > wall_hit.x)
			return (&game->west);
		else
			return (&game->east);
	}
	if (y_fractional == 0)
	{
		if (game->player_pos.y > wall_hit.y)
			return (&game->north);
		else
			return (&game->south);
	}
	return (NULL);
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
