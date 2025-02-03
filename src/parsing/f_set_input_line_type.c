/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_input_line_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:44:09 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_line_type	f_set_input_line_type(t_game *game, char *line)
{
	char		**words;
	t_line_type	type;

	if (*line == '\0')
		return (EMPTY);
	words = f_split(game, line, ' ');
	if (f_strcmp(words[0], "NO") == 0)
		type = NORTH;
	else if (f_strcmp(words[0], "EA") == 0)
		type = EAST;
	else if (f_strcmp(words[0], "SO") == 0)
		type = SOUTH;
	else if (f_strcmp(words[0], "WE") == 0)
		type = WEST;
	else if (f_strcmp(words[0], "F") == 0)
		type = FLOOR;
	else if (f_strcmp(words[0], "C") == 0)
		type = CEILING;
	else if (f_is_map_line(line))
		type = MAP;
	else
		type = WRONG;
	return (type);
}
