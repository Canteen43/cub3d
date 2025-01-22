/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_extract_game_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:13:56 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/21 14:13:38 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Static functions
static void	sf_set_angle(t_game *game, char c);

void	f_extract_game_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (f_strchr("NESW", game->map[i][j]))
			{
				sf_set_angle(game, game->map[i][j]);
				game->map[i][j] = '0';
				game->player_pos.x = j + 0.5f;
				game->player_pos.y = i + 0.5f;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	sf_set_angle(t_game *game, char c)
{
	if (c == 'E')
		game->player_angle = PI * 0;
	if (c == 'N')
		game->player_angle = PI * 0.5;
	if (c == 'W')
		game->player_angle = PI * 1.0;
	if (c == 'S')
		game->player_angle = PI * 1.5;
}
