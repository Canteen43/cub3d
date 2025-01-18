/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_key_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:16:07 by glevin            #+#    #+#             */
/*   Updated: 2025/01/18 16:02:18 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	f_key_release(int keycode, t_player *player)
{
	if (keycode == XK_w)
		player->key_up = false;
	if (keycode == XK_s)
		player->key_down = false;
	if (keycode == XK_a)
		player->key_left = false;
	if (keycode == XK_d)
		player->key_right = false;
	if (keycode == XK_Left)
		player->left_rotate = false;
	if (keycode == XK_Right)
		player->right_rotate = false;
	return (0);
}
