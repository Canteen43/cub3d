/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_open_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:47:20 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// Static functions:
bool	sf_space_adjacent_to_non_wall(t_game *game, int i, int j);

void	f_check_open_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (sf_space_adjacent_to_non_wall(game, i, j))
				f_graceful_exit(game, 1, __func__, "Open wall found.");
			j++;
		}
		j = 0;
		i++;
	}
}

bool	sf_space_adjacent_to_non_wall(t_game *game, int i, int j)
{
	if (f_strchr("NESW0", game->map[i][j]))
	{
		if (i == 0 || game->map[i - 1][j] == ' ')
			return (true);
		if (j == game->map_line_width - 1 || game->map[i][j + 1] == ' ')
			return (true);
		if (i == game->map_line_count - 1 || game->map[i + 1][j] == ' ')
			return (true);
		if (j == 0 || game->map[i][j - 1] == ' ')
			return (true);
	}
	return (false);
}
