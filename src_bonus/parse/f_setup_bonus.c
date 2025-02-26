/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_setup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:14:34 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/25 17:04:38 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_setup_bonus(t_game *game)
{
	game->ceiling_color = SKY_BLUE;
	game->floor_color = POKEGRASS;
	game->bonus_cuttable.path = "textures/cuttable.xpm";
	game->bonus_wall.path = "textures/tree.xpm";
	game->bonus_charmander.path = "textures/charmander.xpm";
	game->bonus_pokeball_map.path = "textures/pokeball_map.xpm";
	game->bonus_pokeball_minimap.path = "textures/pokeball_minimap.xpm";
	game->bonus_team_rocket.path = "textures/team_rocket.xpm";
	game->win_logo.path = "textures/win_logo.xpm";
	f_setup_bonus_map(game);
}
