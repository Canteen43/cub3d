/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_load_dir_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:04:09 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/23 18:43:27 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_load_dir_textures(t_game *game)
{
	f_load_texture(game, &game->north);
	f_load_texture(game, &game->east);
	f_load_texture(game, &game->south);
	f_load_texture(game, &game->west);
}
