/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_graceful_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:41:41 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/12 17:14:30 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_graceful_exit(t_main *main, int exit_code, const char *func,
		char *message)
{
	if (exit_code)
		f_print_error(func, message);
	f_gc_clean(main);
	exit(exit_code);
}
