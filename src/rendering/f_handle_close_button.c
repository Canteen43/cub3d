/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_close_button.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:24:31 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/18 16:08:49 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Handles the close button of the window. Exits gracefully.*/
int	f_handle_close_button(void *param)
{
	t_main	*main;

	main = (t_main *)param;
	f_graceful_exit(main, 0, NULL, NULL);
	return (1);
}
