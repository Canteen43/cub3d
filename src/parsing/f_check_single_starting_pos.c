/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_single_starting_pos.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:05:33 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_check_single_starting_pos(t_game *game)
{
	int		i;
	int		j;
	bool	startpos_found;

	i = 0;
	j = 0;
	startpos_found = false;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (f_strchr("NESW", game->map[i][j]))
			{
				if (!startpos_found)
					startpos_found = true;
				else if (startpos_found)
					f_graceful_exit(game, 1, __func__, "Multiple start pos.");
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (!startpos_found)
		f_graceful_exit(game, 1, __func__, "No start pos found.");
}
