/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:20:24 by glevin            #+#    #+#             */
/*   Updated: 2025/01/22 17:35:26 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Static functions:
static void	sf_print_column(t_game *game, int ray, int wall_height);

void	f_draw_walls(t_game *game)
{
	int			ray;
	float		ray_angle;
	t_coords	wall_hit;
	float		fixed_distance;
	int			wall_height;

	ray = 0;
	while (ray < WIDTH)
	{
		ray_angle = game->player_angle + FOV / 2 - ray * FOV / WIDTH;
		wall_hit = f_next_wall_hit(game, game->player_pos, ray_angle);
		fixed_distance = f_cosine_distance(game->player_pos, wall_hit,
				game->player_angle, ray_angle);
		wall_height = WIDTH / (fixed_distance * 2.0 * tan(FOV / 2.0));
		sf_print_column(game, ray, wall_height);
		ray++;
	}
}

static void	sf_print_column(t_game *game, int ray, int wall_height)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < (HEIGHT / 2 - wall_height / 2))
			f_put_pixel(ray, y, game->ceiling_color, game);
		else if (y > (HEIGHT / 2 + wall_height / 2))
			f_put_pixel(ray, y, game->floor_color, game);
		else
			f_put_pixel(ray, y, SALMON, game);
		y++;
	}
}
