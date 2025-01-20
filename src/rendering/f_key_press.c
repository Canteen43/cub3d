/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_key_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:15:12 by glevin            #+#    #+#             */
/*   Updated: 2025/01/20 20:07:26 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	f_key_press(int keycode, t_player *player)
{
	if (keycode == XK_Escape)
		f_graceful_exit(player->main, 0, NULL, NULL);
	if (keycode == XK_w)
		player->key_up = true;
	if (keycode == XK_s)
		player->key_down = true;
	if (keycode == XK_a)
		player->key_left = true;
	if (keycode == XK_d)
		player->key_right = true;
	if (keycode == XK_Left)
		player->left_rotate = true;
	if (keycode == XK_Right)
		player->right_rotate = true;
	if (keycode == XK_space)
		f_debug_info(player);
	return (0);
}
