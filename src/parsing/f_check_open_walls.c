/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_open_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:47:20 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/12 13:13:20 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Static functions:
bool	sf_space_adjacent_to_non_wall(t_main *main, int i, int j);

void	f_check_open_walls(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (main->map[i])
	{
		while (main->map[i][j])
		{
			if (sf_space_adjacent_to_non_wall(main, i, j))
				f_graceful_exit(main, 1, __func__, "Open wall found.");
			j++;
		}
		j = 0;
		i++;
	}
}

bool	sf_space_adjacent_to_non_wall(t_main *main, int i, int j)
{
	if (f_strchr("NESW0", main->map[i][j]))
	{
		if (i == 0 || main->map[i - 1][j] == ' ')
			return (true);
		if (j == main->map_line_width - 1 || main->map[i][j + 1] == ' ')
			return (true);
		if (i == main->map_line_count - 1 || main->map[i + 1][j] == ' ')
			return (true);
		if (j == 0 || main->map[i][j - 1] == ' ')
			return (true);
	}
	return (false);
}
