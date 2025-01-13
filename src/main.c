/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:45:06 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/13 16:44:12 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
}

void	f_init_game(t_game *game)
{
	f_init_player(&game->player);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line,
			&game->endian);
	printf("endian: %i", game->endian);
	fflush(stdout);
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
	return (0);
}

void	f_move_player(t_player *player)
{
	if (player->key_up)
		player->y -= SPEED;
	if (player->key_down)
		player->y += SPEED;
	if (player->key_right)
		player->x += SPEED;
	if (player->key_left)
		player->x -= SPEED;
}

int	f_draw_loop(t_game *game)
{
	t_player	*player;

	player = &game->player;
	f_move_player(player);
	f_draw_square(player->x, player->y, 5, 0x00FFff, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
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
	f_init_game(&game);
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
