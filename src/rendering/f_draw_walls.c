/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:20:24 by glevin            #+#    #+#             */
/*   Updated: 2025/01/25 13:28:02 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Static functions:
static void	sf_print_column(t_game *game, int ray, int wall_height,
				t_coords wall_hit);

void	f_draw_walls(t_game *game)
{
	int			ray;
	float		ray_angle;
	t_coords	wall_hit;
	float		distance;
	int			wall_height;

	ray = 0;
	while (ray < WIDTH)
	{
		ray_angle = game->player_angle + FOV / 2 - ray * FOV / WIDTH;
		wall_hit = f_next_wall_hit(game, game->player_pos, ray_angle);
		distance = f_cosine_distance(game->player_pos, wall_hit,
				game->player_angle, ray_angle);
		wall_height = WIDTH / (distance * 2.0 * tan(FOV / 2.0));
		sf_print_column(game, ray, wall_height, wall_hit);
		ray++;
	}
}

static void	sf_print_column(t_game *game, int x, int wall_height,
		t_coords wall_hit)
{
	int	y;
	int	color;
	int	ceiling_threshold;
	int	floor_threshold;

	ceiling_threshold = HEIGHT / 2 - wall_height / 2;
	floor_threshold = HEIGHT / 2 + wall_height / 2;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < ceiling_threshold)
			f_put_pixel(x, y, game->ceiling_color, game);
		else if (y > floor_threshold)
			f_put_pixel(x, y, game->floor_color, game);
		else
		{
			color = f_get_texture(y, game, wall_height, wall_hit);
			f_put_pixel(x, y, color, game);
		}
		y++;
	}
}
