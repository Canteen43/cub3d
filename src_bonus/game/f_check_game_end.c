/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_game_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:55:12 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/25 17:10:14 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_check_game_end(t_game *game)
{
	struct timeval	now;
	t_rect			area;

	if (!game->finished)
		return ;
	gettimeofday(&now, NULL);
	if (f_time_diff_ms(&now, &game->game_end) < 200)
		return ;
	area.height = game->win_logo.height;
	area.width = game->win_logo.width;
	area.top_left.x = WIDTH / 2 - area.width / 2;
	area.top_left.y = HEIGHT / 2 - area.height / 2;
	f_draw_from_tex_to_area(game, &game->win_logo, area);
}
