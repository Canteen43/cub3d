/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_destroy_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:20:40 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 11:28:08 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_destroy_images(t_game *game)
{
	t_img	*current;

	current = game->img_head;
	while (current)
	{
		mlx_destroy_image(game->mlx, current->ptr);
		current = current->next;
	}
}
