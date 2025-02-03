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

#include "main.h"

// Static functions:
static float	sf_get_rel_x(t_coords wall_hit, t_dir dir);
static t_tex	*sf_determine_texture(t_game *game, t_dir dir);
static t_tex	*sf_determine_bonus_texture(t_game *game, t_dir dir,
					t_coords wall_hit, t_coords relative);

int	f_get_tex_color(t_game *game, t_coords wall_hit, float relative_y)
{
	t_dir		dir;
	t_tex		*texture;
	t_coords	relative;
	int			color;

	dir = f_determine_direction(game, wall_hit);
	relative.x = sf_get_rel_x(wall_hit, dir);
	relative.y = relative_y;
	if (!game->bonus)
		texture = sf_determine_texture(game, dir);
	else
		texture = sf_determine_bonus_texture(game, dir, wall_hit, relative);
	color = f_get_pixel(game, texture, relative);
	return (color);
}

static float	sf_get_rel_x(t_coords wall_hit, t_dir dir)
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
	return (fraction);
}

static t_tex	*sf_determine_texture(t_game *game, t_dir dir)
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

static t_tex	*sf_determine_bonus_texture(t_game *game, t_dir dir,
		t_coords wall_hit, t_coords relative)
{
	t_int_xy	tile;

	tile = f_determine_tile_coords(game, wall_hit, dir);
	if (game->map[tile.y][tile.x] == '1')
		return (&game->bonus_wall);
	else
		return (&game->bonus_cuttable);
	(void)relative;
}
