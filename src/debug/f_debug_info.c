/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_debug_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:04:06 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/21 15:35:07 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_debug_info(t_game *game)
{
	printf("Next grid hit: X=%f, Y=%f\n", game->grid_hit.x,
		game->grid_hit.y);
	if (f_is_wall(game, game->grid_hit))
		printf("Is wall\n");
	printf("Next wall hit: X=%f, Y=%f\n", game->wall_hit.x,
		game->wall_hit.y);
	printf("--------------------------------\n");
}
