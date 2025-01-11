/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_config_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:35:13 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/11 11:14:02 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_set_config_data(t_main *main, char **cublines)
{
	int			i;
	t_line_typ	type;
	bool		config_complete;

	i = 0;
	config_complete = false;
	while (cublines[i])
	{
		type = f_set_input_line_type(cublines[i]);
		if (type == WRONG)
			error wrong line;
		if (type == MAP && config_complete)
			end function;
		if (type == MAP && !config_complete)
			error uncomplete config before map;
		if (type is config)
			set config;
	}
}
