/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_for_invalid_map_lines.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:34:32 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_check_for_invalid_map_lines(t_game *game)
{
	int			i;
	char		**lines;

	lines = game->cubfile_line_by_line;
	i = 0;
	while (lines[i] && f_set_input_line_type(game, lines[i]) != MAP)
		i++;
	if (lines[i] == NULL)
		f_graceful_exit(game, 1, __func__, "No map line found.");
	while (lines[i] && f_set_input_line_type(game, lines[i]) == MAP)
		i++;
	while (lines[i] && f_set_input_line_type(game, lines[i]) == EMPTY)
		i++;
	if (lines[i] != NULL)
		f_graceful_exit(game, 1, __func__, "Non-empty line found after map.");
}
