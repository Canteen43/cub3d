/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_graceful_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:41:41 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 11:30:44 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_graceful_exit(t_game *game, int exit_code, const char *func,
		char *message)
{
	f_destroy_images(game);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (exit_code)
		f_print_error(func, message);
	f_gc_clean(game);
	exit(exit_code);
}
