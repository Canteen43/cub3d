/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:17:39 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/21 14:16:14 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_set_map(t_game *game)
{
	f_check_for_invalid_map_lines(game);
	f_set_map_dimensions(game);
	f_create_map_array(game);
	f_fill_map_array(game);
	f_check_open_walls(game);
	f_check_single_starting_pos(game);
	f_extract_game_pos(game);
}
