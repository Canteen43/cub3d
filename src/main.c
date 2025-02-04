/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:45:06 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 10:23:17 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	main(int argc, char **argv)
{
	t_game	game;

	f_init_main(&game);
	f_check_args(&game, argc, argv);
	f_parse_input_file(&game, argv);
	f_init_mlx(&game);
	mlx_loop_hook(game.mlx, f_game_loop, &game);
	mlx_loop(game.mlx);
}
