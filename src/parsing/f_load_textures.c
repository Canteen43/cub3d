/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_load_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:04:09 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/26 17:46:23 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Static functions:
static void	sf_load_one_texture(t_game *game, t_tex *tex, int direction);

void	f_load_textures(t_game *game)
{
	sf_load_one_texture(game, &game->north, 1);
	sf_load_one_texture(game, &game->east, 2);
	sf_load_one_texture(game, &game->south, 3);
	sf_load_one_texture(game, &game->west, 4);
}

static void	sf_load_one_texture(t_game *game, t_tex *tex, int direction)
{
	tex->img_ptr = mlx_xpm_file_to_image(game->mlx, tex->path, &tex->width,
			&tex->height);
	if (tex->img_ptr == NULL)
		f_graceful_exit(game, 1, __func__, "Error loading texture.");
	tex->data = mlx_get_data_addr(tex->img_ptr, &tex->bpp, &tex->size_line,
			&tex->endian);
	tex->direction = direction;
}
