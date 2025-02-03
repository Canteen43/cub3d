/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:27:28 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	f_handle_mouse(int x, int y, void *param)
{
	t_game	*game;
	float	dx;
	float	angle;

	game = (t_game *)param;
	(void)y;
	dx = (x - WIDTH / 2);
	angle = (dx / WIDTH) * FOV;
	game->player_angle -= angle;
	mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
