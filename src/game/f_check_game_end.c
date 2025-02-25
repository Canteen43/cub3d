/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_game_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:55:12 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/25 14:38:45 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_check_game_end(t_game *game)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	if (game->finished && f_time_diff_ms(&now, &game->game_end) > 200)
		mlx_string_put(game->mlx, game->win, WIDTH / 1.9, HEIGHT / 1.8, PURPLE,
			"YOU WIN!");
}
