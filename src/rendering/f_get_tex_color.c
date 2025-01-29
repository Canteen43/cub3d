/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_tex_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:23:28 by glevin            #+#    #+#             */
/*   Updated: 2025/01/29 16:21:52 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Static functions:
static t_dir	sf_determine_direction(t_game *game, t_coords wall_hit);
static t_tex	*sf_determine_texture(t_game *game, t_dir dir,
					t_coords wall_hit);
static float	sf_get_tex_x(t_coords wall_hit, t_tex *tex, t_dir dir);
static float	sf_get_tex_y(t_tex *tex, float ratio);

int	f_get_tex_color(t_game *game, t_coords wall_hit, float wall_height_ratio)
{
	t_dir		direction;
	t_tex		*texture;
	t_coords	tex_coords;
	int			color;

	direction = sf_determine_direction(game, wall_hit);
	texture = sf_determine_texture(game, direction, wall_hit);
	tex_coords.y = sf_get_tex_y(texture, wall_height_ratio);
	tex_coords.x = sf_get_tex_x(wall_hit, texture, direction);
	color = f_get_pixel(game, texture, tex_coords);
	return (color);
}

static t_dir	sf_determine_direction(t_game *game, t_coords wall_hit)
{
	float	dummy;

	if (modff(wall_hit.x, &dummy) == 0)
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

static t_tex	*sf_determine_texture(t_game *game, t_dir dir,
		t_coords wall_hit)
{
	char	tile_type;

	if (!game->bonus)
	{
		if (dir == north)
			return (&game->north);
		else if (dir == east)
			return (&game->east);
		else if (dir == south)
			return (&game->south);
		else
			return (&game->west);
	}
	tile_type = f_determine_tile_type(game, wall_hit, dir);
	if (tile_type == '1')
		return (&game->bonus_wall);
	else
		return (&game->bonus_cuttable);
}

static float	sf_get_tex_y(t_tex *tex, float ratio)
{
	if (ratio < 0)
		ratio = 0;
	return (ratio * tex->height);
}

static float	sf_get_tex_x(t_coords wall_hit, t_tex *tex, t_dir dir)
{
	float	dummy;
	float	fraction;

	if (dir == north)
		fraction = modff(wall_hit.x, &dummy);
	else if (dir == east)
		fraction = modff(wall_hit.y, &dummy);
	else if (dir == south)
		fraction = 1 - modff(wall_hit.x, &dummy);
	else
		fraction = 1 - modff(wall_hit.y, &dummy);
	return (fraction * tex->width);
}
