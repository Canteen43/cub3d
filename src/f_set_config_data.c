/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_config_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:35:13 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/08 19:15:26 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_set_config_data(t_main *main, char **cublines)
{
	int			i;
	t_line_typ	type;

	i = 0;
	while (cublines[i])
	{
		type = f_set_input_line_type(cublines[i]);
	}
}

static void	sf_line_to_data(char *line)
{
	char	**res;

	res = f_split(line, ' ');
	if (!res || res[1] || res[2])
		something;
	if (!f_strscmp(res[i], 6, "NO", "EA", "SO", "WE", "F", "C"))
		f_error_and_exit("Found unexpected line", 1);
	f_free_split(res);
}
