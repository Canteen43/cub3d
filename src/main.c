/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:45:06 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/27 18:02:35 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	f_init(&game);
	f_check_args(&game, argc, argv);
	f_handle_cub_file(&game, argv);
	f_start_mlx(&game);
	mlx_hook(game.win, 2, 1L << 0, f_key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, f_key_release, &game);
	mlx_hook(game.win, 17, 0, f_handle_close_button, &game);
	mlx_hook(game.win, 6, 1L << 6, f_handle_mouse, &game);
	mlx_mouse_move(game.mlx, game.win, WIDTH / 2, HEIGHT / 2);
	mlx_loop_hook(game.mlx, f_game_loop, &game);
	mlx_loop(game.mlx);
}
