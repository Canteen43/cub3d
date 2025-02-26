/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_wall_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:17:35 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_coords	f_next_wall_hit(t_game *game, t_coords current, float angle)
{
	t_coords	wall_hit;

	wall_hit = f_next_grid_hit(current, angle);
	while (!f_is_wall(game, wall_hit))
		wall_hit = f_next_grid_hit(wall_hit, angle);
	return (wall_hit);
}
