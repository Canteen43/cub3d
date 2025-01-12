/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_for_invalid_map_lines.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:34:32 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/12 11:16:09 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_check_for_invalid_map_lines(t_main *main)
{
	int			i;
	char		**lines;

	lines = main->cubfile_line_by_line;
	i = 0;
	while (f_set_input_line_type(lines[i]) != MAP)
		i++;
	while (f_set_input_line_type(lines[i]) == MAP)
		i++;
	while (f_set_input_line_type(lines[i]) == EMPTY)
		i++;
	if (lines[i] != NULL)
		f_graceful_exit(main, 1, __func__, "Non-empty line found after map.");
}
