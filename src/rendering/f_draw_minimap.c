/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:31:38 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/27 15:05:23 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	f_draw_minimap(t_game *game)
// {
// 	int	y;
// 	int	x;

// 	y = -1;
// 	f_draw_full_square(game, (t_square){YELLOW, game->map_line_count
// 		* MINIBLOCK, (t_coords){0, 0}});
// 	while (game->map[++y])
// 	{
// 		x = -1;
// 		while (game->map[y][++x])
// 		{
// 			if (game->map[y][x] == '1')
// 			{
// 				f_draw_square(game, (t_square){BLUE, MINIBLOCK, (t_coords){x
// 					* MINIBLOCK, y * MINIBLOCK}});
// 			}
// 		}
// 	}
// 	f_draw_circle_full(game, (t_circle){RED, MINIBLOCK / 3,
// 		(t_coords){game->player_pos.x * MINIBLOCK, game->player_pos.y
// 		* MINIBLOCK}});
// 	f_draw_circle_full(game, (t_circle){PINK, MINIBLOCK / 5,
// 		(t_coords){(game->player_pos.x + 0.3 * cos(game->player_angle))
// 		* MINIBLOCK, (game->player_pos.y - 0.3 * sin(game->player_angle))
// 		* MINIBLOCK}});
// }

// Static functions
static void	sf_draw_map(t_game *game);
static void	sf_draw_rays(t_game *game);

void	f_draw_minimap(t_game *game)
{
	int			radius;
	t_coords	center;

	sf_draw_map(game);
	radius = WALL_BUFFER * game->pix_per_unit;
	center.x = MINI_HEIGHT / 2;
	center.y = MINI_HEIGHT / 2;
	f_draw_circle_full(game, (t_circle){RED, radius, center});
	sf_draw_rays(game);
}

static void	sf_draw_map(t_game *game)
{
	int			y;
	int			x;
	t_coords	pos;

	y = 0;
	while (y < MINI_HEIGHT)
	{
		x = 0;
		while (x < MINI_HEIGHT)
		{
			pos.x = game->player_pos.x - DISTANCE_SEEN + x * (DISTANCE_SEEN * 2
					/ MINI_HEIGHT);
			pos.y = game->player_pos.y - DISTANCE_SEEN + y * (DISTANCE_SEEN * 2
					/ MINI_HEIGHT);
			if (pos.x >= game->map_line_width || pos.x < 0
				|| pos.y >= game->map_line_count || pos.y < 0
				|| game->map[(int)pos.y][(int)pos.x] == '0')
				f_put_pixel(x, y, LIGHT_GRAY, game);
			else
				f_put_pixel(x, y, DARK_GRAY, game);
			x++;
		}
		y++;
	}
}

static void	sf_draw_rays(t_game *game)
{
	int			ray;
	float		ray_angle;
	t_coords	wall_hit;
	t_coords	center;
	t_coords	end;

	ray = 0;
	center.x = MINI_HEIGHT / 2;
	center.y = MINI_HEIGHT / 2;
	while (ray < WIDTH)
	{
		ray_angle = game->player_angle + FOV / 2 - ray * FOV / WIDTH;
		wall_hit = f_next_wall_hit(game, game->player_pos, ray_angle);
		end.x = center.x + (wall_hit.x - game->player_pos.x)
			* game->pix_per_unit;
		if (end.x > MINI_HEIGHT)
			end.x = MINI_HEIGHT;
		end.y = center.y + (wall_hit.y - game->player_pos.y)
			* game->pix_per_unit;
		if (end.y > MINI_HEIGHT)
			end.y = MINI_HEIGHT;
		f_draw_line(game, (t_line){ORANGE, center, end});
		ray += 1;
	}
}
