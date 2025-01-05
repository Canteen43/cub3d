/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_config_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:35:13 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/05 13:41:09 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void f_set_config_data(t_main *main, char ** cublines)
{
	int	i;

	i = 0;
	while (cublines[i])
	{
		