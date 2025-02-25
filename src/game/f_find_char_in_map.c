/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_find_char_in_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:58:07 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/25 17:10:22 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_int_xy	f_find_char_in_map(t_game *game, char c)
{
	t_int_xy	coords;

	coords.y = 0;
	while (coords.y < game->map_line_count)
	{
		coords.x = 0;
		while (coords.x < game->map_line_width)
		{
			if (game->map[coords.y][coords.x] == c)
				return (coords);
			coords.x++;
		}
		coords.y++;
	}
	coords.x = -1;
	coords.y = -1;
	return (coords);
}
