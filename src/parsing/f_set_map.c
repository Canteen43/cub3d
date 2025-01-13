/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:17:39 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/13 13:09:45 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_set_map(t_main *main)
{
	f_check_for_invalid_map_lines(main);
	f_set_map_dimensions(main);
	f_create_map_array(main);
	f_fill_map_array(main);
	f_check_open_walls(main);
	f_check_single_starting_pos(main);
}
