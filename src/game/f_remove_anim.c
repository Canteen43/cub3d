/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_remove_anim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:05:57 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/23 18:42:09 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_remove_anim(t_game *game, t_anim_queue *anim)
{
	if (anim == game->anim_head)
		game->anim_head = anim->next;
	if (anim->prev)
		anim->prev->next = anim->next;
	if (anim->next)
		anim->next->prev = anim->prev;
}
