/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_load_bonus_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:49:53 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/23 18:37:39 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_load_bonus_textures(t_game *game)
{
	f_load_texture(game, &game->bonus_cuttable);
	f_load_texture(game, &game->bonus_wall);
	f_load_texture(game, &game->bonus_charmander);
	f_load_texture(game, &game->bonus_pokeball);
	f_load_anim(game, &game->cut, (t_anim){NULL, 20, 100},
		"textures/animations/cut/cut");
}
