/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_load_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:04:09 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/21 18:26:03 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Static functions:
static void	sf_load_one_texture(t_game *game, t_tex *tex);

void	f_load_textures(t_game *game)
{
	sf_load_one_texture(game, &game->north);
	sf_load_one_texture(game, &game->east);
	sf_load_one_texture(game, &game->south);
	sf_load_one_texture(game, &game->west);
}

static void	sf_load_one_texture(t_game *game, t_tex *tex)
{
	tex->img_ptr = mlx_xpm_file_to_image(game->mlx, tex->path, &tex->width,
			&tex->height);
	if (tex->img_ptr == NULL)
		f_graceful_exit(game, 1, __func__, "Error loading texture.");
}
