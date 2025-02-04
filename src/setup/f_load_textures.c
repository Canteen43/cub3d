/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_load_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:04:09 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 17:08:44 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

// Static functions:
static void	sf_load_one_texture(t_game *game, t_tex *tex);

void	f_load_textures(t_game *game)
{
	if (!game->bonus)
	{
		sf_load_one_texture(game, &game->north);
		sf_load_one_texture(game, &game->east);
		sf_load_one_texture(game, &game->south);
		sf_load_one_texture(game, &game->west);
	}
	else
	{
		sf_load_one_texture(game, &game->bonus_cuttable);
		sf_load_one_texture(game, &game->bonus_wall);
		sf_load_one_texture(game, &game->bonus_charmander);
	}
}

static void	sf_load_one_texture(t_game *game, t_tex *tex)
{
	tex->img_ptr = mlx_xpm_file_to_image(game->mlx, tex->path, &tex->width,
			&tex->height);
	if (tex->img_ptr == NULL)
		f_graceful_exit(game, 1, __func__, "Error loading texture.");
	tex->data = mlx_get_data_addr(tex->img_ptr, &tex->bpp, &tex->size_line,
			&tex->endian);
}
