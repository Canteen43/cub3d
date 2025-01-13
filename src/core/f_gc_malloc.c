/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_gc_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:16:46 by glevin            #+#    #+#             */
/*   Updated: 2025/01/12 17:11:19 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to add a node to the garbage collector list
t_gnode	*f_gc_add_node(t_main *main, void *ptr)
{
	t_gnode	*new_node;

	new_node = (t_gnode *)malloc(sizeof(t_gnode));
	if (!new_node)
		return (NULL);
	new_node->ptr = ptr;
	new_node->next = main->gc_head;
	main->gc_head = new_node;
	return (new_node);
}

// Wrapper for malloc that integrates with garbage collector
void	*f_gc_malloc(t_main *main, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	if (f_gc_add_node(main, ptr) == NULL)
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}
