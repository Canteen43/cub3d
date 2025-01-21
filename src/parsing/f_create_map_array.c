/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_create_map_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:17:49 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/21 14:07:43 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_create_map_array(t_game *game)
{
	int	i;

	game->map = f_gc_malloc(game, (game->map_line_count + 1) * sizeof(void *));
	i = 0;
	while (i < game->map_line_count)
	{
		game->map[i] = f_gc_malloc(game, (game->map_line_width + 1)
				* sizeof(char));
		i++;
	}
	game->map[i] = NULL;
}
