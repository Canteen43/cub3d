/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fill_map_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:44:49 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/12 12:45:21 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Static functions:
static void	sf_fill_line(t_main *main, int offset, int i);

void	f_fill_map_array(t_main *main)
{
	int		i;
	int		j;
	int		offset;
	char	**lines;

	lines = main->cubfile_line_by_line;
	offset = 0;
	while (f_set_input_line_type(lines[offset]) != MAP)
		offset++;
	i = 0;
	while (f_set_input_line_type(lines[offset + i]) == MAP)
	{
		sf_fill_line(main, offset, i);
		i++;
	}
}

static void	sf_fill_line(t_main *main, int offset, int i)
{
	int		j;
	char	**lines;

	lines = main->cubfile_line_by_line;
	j = 0;
	while (lines[offset + i][j])
	{
		main->map[i][j] = lines[offset + i][j];
		j++;
	}
	while (j < main->main->map_line_width)
	{
		main->map[i][j] = ' ';
		j++;
	}
	main->map[i][j] = '\0';
}
