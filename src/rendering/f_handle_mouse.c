/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:27:28 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/27 18:07:34 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	f_handle_mouse(int x, int y, void *param)
{
	t_game	*game;
	float	dx;

	(void) y;
	game = (t_game *)param;
	dx = (x - WIDTH / 2) / (WIDTH / 2);
	game->player_angle += -dx * FOV / 2;
	// mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
