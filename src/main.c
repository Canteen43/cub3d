/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:45:06 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	main(int argc, char **argv)
{
	t_game	game;

	f_init(&game);
	f_check_args(&game, argc, argv);
	f_handle_cub_file(&game, argv);
	f_start_mlx(&game);
	f_set_hooks(&game);
	mlx_loop(game.mlx);
}
