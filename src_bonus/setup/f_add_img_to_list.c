/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_add_img_to_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:10:45 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 12:58:13 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_add_image_to_list(t_game *game, void *ptr)
{
	t_img	*new;

	new = f_gc_malloc(game, sizeof(t_img));
	new->ptr = ptr;
	new->next = game->img_head;
	game->img_head = new;
}
