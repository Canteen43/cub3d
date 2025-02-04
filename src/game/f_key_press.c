/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_key_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:15:12 by glevin            #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	f_key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		f_graceful_exit(game, 0, NULL, NULL);
	if (keycode == XK_w)
		game->key_up = true;
	if (keycode == XK_s)
		game->key_down = true;
	if (keycode == XK_a)
		game->key_left = true;
	if (keycode == XK_d)
		game->key_right = true;
	if (keycode == XK_Left)
		game->left_rotate = true;
	if (keycode == XK_Right)
		game->right_rotate = true;
	if (keycode == XK_Return)
		f_debug_info(game);
	if (keycode == XK_space && game->bonus)
		f_remove_obstacle(game);
	return (0);
}
