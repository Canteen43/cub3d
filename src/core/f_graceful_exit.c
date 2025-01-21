/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_graceful_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:41:41 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/21 14:07:43 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_graceful_exit(t_game *game, int exit_code, const char *func,
		char *message)
{
	if (exit_code)
		f_print_error(func, message);
	f_gc_clean(game);
	exit(exit_code);
}
