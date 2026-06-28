/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_load_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:16:57 by kweihman          #+#    #+#             */
/*   Updated: 2026/06/28 13:56:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_load_anim(t_game *game, t_anim *anim, t_anim params, char *path)
{
	int		i;
	int		buf_size;
	char	*current_path;

	anim->nbr_frames = params.nbr_frames;
	anim->duration_ms = params.duration_ms;
	anim->frames = f_gc_malloc(game, sizeof(t_tex) * params.nbr_frames);
	i = 0;
	while (i < params.nbr_frames)
	{
		buf_size = f_strlen(path) + 8 + 1;
		current_path = f_gc_malloc(game, buf_size);
		snprintf(current_path, buf_size, "%s_%03d.xpm", path, i);
		anim->frames[i].path = current_path;
		f_load_texture(game, &anim->frames[i]);
		i++;
	}
}
