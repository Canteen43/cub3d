/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_create_map_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:17:49 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/12 12:23:14 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_create_map_array(t_main *main)
{
	int	i;

	main->map = f_gc_malloc(main, (main->map_line_count + 1) * sizeof(void *));
	i = 0;
	while (i < main->map_line_count)
	{
		main->map[i] = f_gc_malloc(main, (main->map_line_width + 1)
				* sizeof(char));
		i++;
	}
	main->map[i] = NULL;
}
