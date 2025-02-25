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

#include "headers.h"

// Static functions:
static float	sf_get_rel_x(t_coords wall_hit, t_dir dir);
static t_tex	*sf_determine_texture(t_game *game, t_dir dir);
static t_tex	*sf_determine_bonus_texture(t_game *game, t_int_xy tile);

int	f_get_tex_color(t_game *game, t_coords wall_hit, float relative_y)
{
	t_dir		dir;
	t_tex		*texture;
	t_coords	relative;
	int			color;
	t_int_xy	tile;

	dir = f_determine_direction(game, wall_hit);
	relative.x = sf_get_rel_x(wall_hit, dir);
	relative.y = relative_y;
	if (!game->bonus)
	{
		texture = sf_determine_texture(game, dir);
		color = f_get_pixel(game, texture, relative);
		return (color);
	}
	tile = f_determine_tile_coords(game, wall_hit, dir);
	texture = sf_determine_bonus_texture(game, tile);
	color = f_get_pixel(game, texture, relative);
	f_superpose_anim(game, tile, relative, &color);
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

static t_tex	*sf_determine_bonus_texture(t_game *game, t_int_xy tile)
{
	char	type;

	type = game->map[tile.y][tile.x];
	if(game->debug_flag == true)
	{
		printf("tile.x: %i, tile.y: %i", tile.x, tile.y);
		game->debug_flag = false;
	}
	if (type == '1')
		return (&game->bonus_wall);
	else if (type == 'P')
		return (&game->bonus_pokeball_map);
	else if (type == 'R')
		return (&game->bonus_team_rocket);
	else
		return (&game->bonus_cuttable);
}
