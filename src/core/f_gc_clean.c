/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_gc_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:00:37 by glevin            #+#    #+#             */
/*   Updated: 2025/01/12 16:57:01 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to clean all allocated memory in the garbage collector
void	f_gc_clean(t_main *main)
{
	t_gnode	*tmp;
	t_gnode	*current;

	current = main->gc_head;
	while (current)
	{
		if (current->ptr)
			free(current->ptr);
		tmp = current;
		current = current->next;
		free(tmp);
	}
	main->gc_head = NULL;
}
