/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_map_dimensions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:14:56 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_set_map_dimensions(t_game *game)
{
	int		i;
	char	**lines;

	lines = game->cubfile_line_by_line;
	i = 0;
	while (f_set_input_line_type(game, lines[i]) != MAP)
		i++;
	while (f_set_input_line_type(game, lines[i]) == MAP)
	{
		if ((int)f_strlen(lines[i]) > game->map_line_width)
			game->map_line_width = (int)f_strlen(lines[i]);
		game->map_line_count++;
		i++;
	}
}
