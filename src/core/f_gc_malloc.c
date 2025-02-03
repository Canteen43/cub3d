/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_gc_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:16:46 by glevin            #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// Function to add a node to the garbage collector list
t_gnode	*f_gc_add_node(t_game *game, void *ptr)
{
	t_gnode	*new_node;

	new_node = (t_gnode *)malloc(sizeof(t_gnode));
	if (!new_node)
		return (NULL);
	new_node->ptr = ptr;
	new_node->next = game->gc_head;
	game->gc_head = new_node;
	return (new_node);
}

// Wrapper for malloc that integrates with garbage collector
void	*f_gc_malloc(t_game *game, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	if (f_gc_add_node(game, ptr) == NULL)
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}
