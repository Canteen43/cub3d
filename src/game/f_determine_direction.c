/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_determine_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:53:13 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/24 11:00:41 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_dir	f_determine_direction(t_game *game, t_coords wall_hit)
{
	if (f_is_round(wall_hit.x))
	{
		if (game->player_pos.x > wall_hit.x)
			return (west);
		else
			return (east);
	}
	else
	{
		if (game->player_pos.y > wall_hit.y)
			return (north);
		else
			return (south);
	}
}
