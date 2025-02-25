/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_setup_bonus_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:34:47 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/25 16:53:12 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_setup_bonus_map(t_game *game)
{
	game->map = game->cubfile_line_by_line;
	game->map_line_count = 0;
	game->map_line_width = 0;
	while (game->map[game->map_line_count])
		game->map_line_count++;
	while (game->map[0][game->map_line_width])
		game->map_line_width++;
	game->player_angle = PI / 2;
	game->player_pos = (t_coords){68.5, 9.5};
}
