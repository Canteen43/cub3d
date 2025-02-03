/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_determine_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:53:13 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_dir	f_determine_direction(t_game *game, t_coords wall_hit)
{
	float	dummy;

	if (modff(wall_hit.x, &dummy) == 0)
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
