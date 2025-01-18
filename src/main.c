/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:45:06 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/18 16:09:43 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_main	main;
	t_game	game;

	f_init(&main);
	f_check_args(&main, argc, argv);
	f_handle_cub_file(&main, argv);
	f_init_game(&game, &main);
	mlx_hook(game.win, 2, 1L << 0, f_key_press, &game.player);
	mlx_hook(game.win, 3, 1L << 1, f_key_release, &game.player);
	mlx_hook(game.win, 17, 0, f_handle_close_button, &main);
	mlx_loop_hook(game.mlx, f_draw_loop, &game);
	mlx_loop(game.mlx);
}
