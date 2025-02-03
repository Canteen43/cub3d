/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_close_button.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:24:31 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*Handles the close button of the window. Exits gracefully.*/
int	f_handle_close_button(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	f_graceful_exit(game, 0, NULL, NULL);
	return (1);
}
