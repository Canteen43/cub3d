/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:46:20 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	f_init(t_game *game)
{
	f_bzero(game, sizeof(t_game));
	game->ceiling_color = -1;
	game->floor_color = -1;
	game->pix_per_unit = MINI_HEIGHT / (DISTANCE_SEEN * 2);
	game->focal_length = 2.0 * tan(FOV / 2.0);
}
