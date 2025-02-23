/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add_to_anim_queue.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:52:55 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/23 18:41:59 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_add_to_anim_queue(t_game *game, t_int_xy coords, t_anim *anim)
{
	t_anim_queue	*new;

	new = f_gc_malloc(game, sizeof(t_anim_queue));
	if (gettimeofday(&new->start, NULL))
		f_graceful_exit(game, 1, __func__, "Gettimeofday() failed");
	new->anim = anim;
	new->coords = coords;
	new->prev = NULL;
	new->next = game->anim_head;
	game->anim_head = new;
}
