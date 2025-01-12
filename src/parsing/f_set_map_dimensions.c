/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_map_dimensions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:14:56 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/12 11:18:59 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_set_map_dimensions(t_main *main)
{
	int		i;
	char	**lines;

	lines = main->cubfile_line_by_line;
	i = 0;
	while (f_set_input_line_type(lines[i]) != MAP)
		i++;
	while (f_set_input_line_type(lines[i]) == MAP)
	{
		if (strlen(lines[i]) > main->map_line_width)
			main->map_line_width = strlen(lines[i]);
		main->map_line_count++;
		i++;
	}
	while (f_set_input_line_type(lines[i]) == EMPTY)
		i++;
	if (lines[i] != NULL)
		f_graceful_exit(main, 1, __func__, "Non-empty line found after map.");
}
