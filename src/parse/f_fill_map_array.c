/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fill_map_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:44:49 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

// Static functions:
static void	sf_fill_line(t_game *game, int offset, int i);

void	f_fill_map_array(t_game *game)
{
	int		i;
	int		offset;
	char	**lines;

	lines = game->cubfile_line_by_line;
	offset = 0;
	while (f_set_input_line_type(game, lines[offset]) != MAP)
		offset++;
	i = 0;
	while (f_set_input_line_type(game, lines[offset + i]) == MAP)
	{
		sf_fill_line(game, offset, i);
		i++;
	}
}

static void	sf_fill_line(t_game *game, int offset, int i)
{
	int		j;
	char	**lines;

	lines = game->cubfile_line_by_line;
	j = 0;
	while (lines[offset + i][j])
	{
		game->map[i][j] = lines[offset + i][j];
		j++;
	}
	while (j < game->map_line_width)
	{
		game->map[i][j] = ' ';
		j++;
	}
	game->map[i][j] = '\0';
}
