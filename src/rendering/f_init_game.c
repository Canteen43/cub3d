/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:12:45 by glevin            #+#    #+#             */
/*   Updated: 2025/01/18 12:13:20 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
