/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_error_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:11:46 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/08 18:32:23 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_error_and_exit(char *error, int exit_code)
{
	write(2, error, strlen(error));
	exit(exit_code);
}
