/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:05:50 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/25 17:13:57 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_set_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, f_key_press, game);
	mlx_hook(game->win, 3, 1L << 1, f_key_release, game);
	mlx_hook(game->win, 17, 0, f_handle_close_button, game);
	if (game->bonus == true)
		mlx_hook(game->win, 6, 1L << 6, f_handle_mouse, game);
}
