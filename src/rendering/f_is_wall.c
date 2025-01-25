/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:10:54 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/23 17:12:26 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	f_is_wall(t_game *game, t_coords pos)
{
	char	**map;

	map = game->map;
	if (map[(int)pos.y][(int)pos.x] == '1')
		return (true);
	if (f_is_round(pos.y) && map[(int)pos.y - 1][(int)pos.x] == '1')
		return (true);
	if (f_is_round(pos.x) && map[(int)pos.y][(int)pos.x - 1] == '1')
		return (true);
	// TODO: @Karl, What case does this conditional solve?
	// if (f_is_round(pos.y) && f_is_round(pos.x) && map[(int)pos.y - 1][(int)pos.x
	// 	- 1] == '1')
	// 	return (true);
	return (false);
}
