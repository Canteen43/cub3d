/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:12:45 by glevin            #+#    #+#             */
/*   Updated: 2026/06/27 15:18:14 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

// Static functions:
static void	sf_init_bonus(t_game *game);

void	f_init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		f_graceful_exit(game, 1, __func__, "mlx_init() failed.");
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
		f_graceful_exit(game, 1, __func__, "mlx_new_window() failed.");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		f_graceful_exit(game, 1, __func__, "mlx_new_image() failed.");
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line,
			&game->endian);
	if (!game->data)
		f_graceful_exit(game, 1, __func__, "mlx_get_data_addr() failed.");
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	f_set_hooks(game);
	if (!game->bonus)
		f_load_dir_textures(game);
	else
		sf_init_bonus(game);
}

static void	sf_init_bonus(t_game *game)
{
	f_load_bonus_textures(game);
	mlx_mouse_hide(game->mlx, game->win);
	mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
}
