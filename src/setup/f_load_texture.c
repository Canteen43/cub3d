/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_load_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:43:57 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 12:44:42 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_load_texture(t_game *game, t_tex *tex)
{
	tex->img_ptr = mlx_xpm_file_to_image(game->mlx, tex->path, &tex->width,
			&tex->height);
	if (tex->img_ptr == NULL)
		f_graceful_exit(game, 1, __func__, "Error loading texture.");
	f_add_image_to_list(game, tex->img_ptr);
	tex->data = mlx_get_data_addr(tex->img_ptr, &tex->bpp, &tex->size_line,
			&tex->endian);
}
