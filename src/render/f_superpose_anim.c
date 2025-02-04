/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_superpose_anim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:20:35 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 18:05:07 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

// Static functions:
static t_anim_queue	*sf_current_anim(t_game *game, t_int_xy tile);
static int			sf_current_frame(t_game *game, t_anim_queue *current);

void	f_superpose_anim(t_game *game, t_int_xy tile, t_coords relative,
		int *color)
{
	t_anim_queue	*current_anim;
	int				current_frame;
	int				anim_color;
	t_tex			*tex;

	if (game->map[tile.y][tile.x] == '1')
		return ;
	current_anim = sf_current_anim(game, tile);
	if (!current_anim)
		return ;
	current_frame = sf_current_frame(game, current_anim);
	if (current_frame == -1)
		return ;
	tex = &current_anim->anim->frames[current_frame];
	anim_color = f_get_pixel(game, tex, relative);
	if (anim_color != 0)
		*color = anim_color;
}

static t_anim_queue	*sf_current_anim(t_game *game, t_int_xy tile)
{
	t_anim_queue	*current;

	current = game->anim_head;
	while (current)
	{
		if (current->coords.x == tile.x && current->coords.y == tile.y)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static int	sf_current_frame(t_game *game, t_anim_queue *current)
{
	struct timeval now;
	int time_passed;
	int frame;
	int duration;

	duration = current->anim->duration_ms;
	gettimeofday(&now, NULL);
	time_passed = f_time_diff_ms(&now, &current->start);
	if (time_passed > duration)
	{
		game->map[current->coords.y][current->coords.x] = '0';
		f_remove_anim(game, current);
		return (-1);
	}
	frame = (float)time_passed / duration * current->anim->nbr_frames;
	return (frame);
}
