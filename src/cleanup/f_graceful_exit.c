/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_graceful_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:41:41 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

// Static functions:
static void	sf_cleanup_images(t_game *game);

void	f_graceful_exit(t_game *game, int exit_code, const char *func,
		char *message)
{
	sf_cleanup_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (exit_code)
		f_print_error(func, message);
	f_gc_clean(game);
	exit(exit_code);
}

static void	sf_cleanup_images(t_game *game)
{
	if (game->north.img_ptr)
		mlx_destroy_image(game->mlx, game->north.img_ptr);
	if (game->east.img_ptr)
		mlx_destroy_image(game->mlx, game->east.img_ptr);
	if (game->south.img_ptr)
		mlx_destroy_image(game->mlx, game->south.img_ptr);
	if (game->west.img_ptr)
		mlx_destroy_image(game->mlx, game->west.img_ptr);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
}
