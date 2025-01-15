/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:45:06 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/15 17:33:27 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->angle = PI / 2;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

void	f_init_game(t_game *game, t_main *main)
{
	f_init_player(&game->player);
	game->main = main;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line,
			&game->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

void	f_put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	f_draw_square(int x, int y, int size, int color, t_game *game)
{
	int	i;

	i = -1;
	while (size > ++i)
		f_put_pixel(x + i, y, color, game);
	i = -1;
	while (size > ++i)
		f_put_pixel(x, y + i, color, game);
	i = -1;
	while (size > ++i)
		f_put_pixel(x + size, y + i, color, game);
	i = -1;
	while (size > ++i)
		f_put_pixel(x + i, y + size, color, game);
}

int	key_press(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = true;
	if (keycode == S)
		player->key_down = true;
	if (keycode == A)
		player->key_left = true;
	if (keycode == D)
		player->key_right = true;
	if (keycode == LEFT)
		player->left_rotate = true;
	if (keycode == RIGHT)
		player->right_rotate = true;
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}

void	f_move_player(t_player *player)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->left_rotate)
		player->angle += ANGLE_SPEED;
	if (player->right_rotate)
		player->angle -= ANGLE_SPEED;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;
	if (player->key_up)
	{
		player->x -= cos_angle * SPEED;
		player->y -= sin_angle * SPEED;
	}
	if (player->key_down)
	{
		player->x += cos_angle * SPEED;
		player->y += sin_angle * SPEED;
	}
	if (player->key_right)
	{
		player->x += sin_angle * SPEED;
		player->y -= cos_angle * SPEED;
	}
	if (player->key_left)
	{
		player->x -= sin_angle * SPEED;
		player->y += cos_angle * SPEED;
	}
}

void	f_clear_image(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			f_put_pixel(x, y, 0, game);
	}
}

void	f_draw_map(t_game *game)
{
	int	color;
	int	y;
	int	x;

	color = 0x0000FF;
	y = -1;
	while (game->main->map[++y])
	{
		x = -1;
		while (game->main->map[y][++x])
		{
			if (game->main->map[x][y] == '1')
			{
				f_draw_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
			}
		}
	}
}

bool	f_touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (game->main->map[x][y] == '1')
	{
		return (true);
	}
	return (false);
}

float	f_distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	f_fixed_dist(float x1, float y1, float x2, float y2, t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = f_distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

void	f_draw_walls(float ray_x, float ray_y, t_player *player, t_game *game,
		int i)
{
	float	dist;
	float	height;
	int		start_y;
	int		end;

	dist = f_distance(ray_x - player->x, ray_y - player->y);
	// dist = f_fixed_dist(player->x, player->y, ray_x, ray_y, game);
	height = (BLOCK / dist) * (WIDTH / 2);
	start_y = (HEIGHT - height) / 2;
	end = start_y + height;
	while (start_y < end)
	{
		f_put_pixel(i, start_y, 255, game);
		start_y++;
	}
}

void	f_draw_line(t_player *player, t_game *game, float start_x, int i)
{
	float	ray_x;
	float	ray_y;
	float	cos_angle;
	float	sin_angle;
	bool	touch;

	ray_x = player->x;
	ray_y = player->y;
	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	touch = false;
	while (!f_touch(ray_x, ray_y, game))
	{
		f_put_pixel(ray_x, ray_y, 0xFF0000, game);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	f_draw_walls(ray_x, ray_y, player, game, i);
}

int	f_draw_loop(t_game *game)
{
	t_player	*player;
	float		fraction;
	float		start_x;
	int			i;

	player = &game->player;
	f_move_player(player);
	f_clear_image(game);
	f_draw_map(game);
	fraction = PI / 3 / WIDTH;
	start_x = player->angle - PI / 6 + PI;
	i = 0;
	while (i < WIDTH)
	{
		f_draw_line(player, game, start_x, i);
		start_x += fraction;
		i++;
	}
	f_draw_square(player->x, player->y, 8, 0x00FFff, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	usleep(1000); // To lower the fps and reduce expense to the CPU
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	main;
	t_game	game;

	f_init(&main);
	f_check_args(&main, argc, argv);
	f_handle_cub_file(&main, argv);
	f_print_map(&main);
	f_init_game(&game, &main);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game.player);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game.player);
	mlx_loop_hook(game.mlx, f_draw_loop, &game);
	// f_draw_square(WIDTH / 2, HEIGHT / 2, 10, 0x00FFFF, &game);
	mlx_loop(game.mlx);
	// mlx_hook
	// init_sim
	// run_sim
	// clear_all
}
