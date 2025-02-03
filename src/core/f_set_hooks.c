/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:05:50 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	f_set_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, f_key_press, game);
	mlx_hook(game->win, 3, 1L << 1, f_key_release, game);
	mlx_hook(game->win, 17, 0, f_handle_close_button, game);
	mlx_hook(game->win, 6, 1L << 6, f_handle_mouse, game);
	mlx_mouse_hide(game->mlx, game->win);
	mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	mlx_loop_hook(game->mlx, f_game_loop, game);
}
