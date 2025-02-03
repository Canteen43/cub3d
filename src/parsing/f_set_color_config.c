/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_color_config.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:31:10 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// Static functions:
static void	sf_skip_spaces(char *line, int *i);
static int	sf_get_value(int *target, char *line, int *i, char color);
static int	sf_check_comma(char *line, int *i);

void	f_set_color_config(t_game *game, t_line_type type, char *line)
{
	int	*target;
	int	i;

	if (type == FLOOR)
		target = &game->floor_color;
	if (type == CEILING)
		target = &game->ceiling_color;
	if (*target != -1)
		f_graceful_exit(game, 1, __func__, "Redefintion of color config.");
	i = 0;
	sf_skip_spaces(line, &i);
	i++;
	if (sf_get_value(target, line, &i, 'r'))
		f_graceful_exit(game, 1, __func__, "Wrong value for red config.");
	if (sf_check_comma(line, &i))
		f_graceful_exit(game, 1, __func__, "Comma missing after color config.");
	if (sf_get_value(target, line, &i, 'g'))
		f_graceful_exit(game, 1, __func__, "Wrong value for green config.");
	if (sf_check_comma(line, &i))
		f_graceful_exit(game, 1, __func__, "Comma missing after color config.");
	if (sf_get_value(target, line, &i, 'b'))
		f_graceful_exit(game, 1, __func__, "Wrong value for blue config.");
	if (line[i] != '\0')
		f_graceful_exit(game, 1, __func__, "Extra argument for color config.");
}

static void	sf_skip_spaces(char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
}

static int	sf_get_value(int *target, char *line, int *i, char color)
{
	int	res;

	sf_skip_spaces(line, i);
	if (!f_is_dig(line[*i]))
		return (1);
	res = 0;
	while (f_is_dig(line[*i]))
	{
		res = res * 10 + (line[*i] - '0');
		if (res > 255)
			return (1);
		(*i)++;
	}
	if (color == 'r')
		*target = res * 256 * 256;
	else if (color == 'g')
		*target += res * 256;
	else if (color == 'b')
		*target += res;
	sf_skip_spaces(line, i);
	return (0);
}

static int	sf_check_comma(char *line, int *i)
{
	if (line[*i] != ',')
		return (1);
	(*i)++;
	return (0);
}
