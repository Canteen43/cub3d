/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_load_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:16:57 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 13:51:23 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_load_anim(t_game *game, t_anim *anim, t_anim params, char *path)
{
	int		i;
	int		current_len;
	char	*current_path;

	anim->nbr_frames = params.nbr_frames;
	anim->duration_ms = params.duration_ms;
	anim->frames = f_gc_malloc(game, sizeof(t_tex) * params.nbr_frames);
	i = 0;
	while (i < params.nbr_frames)
	{
		current_len = f_strlen(path) + 8;
		current_path = f_gc_malloc(game, sizeof(char) *(current_len + 1));
		sprintf(current_path, "%s_%03d.xpm", path, i);
		anim->frames[i].path = current_path;
		f_load_texture(game, &anim->frames[i]);
		i++;
	}
}
