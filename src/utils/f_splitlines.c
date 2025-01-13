/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_splitlines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:08:34 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/13 10:38:26 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Static functions:
static int	sf_fill_array(t_main *main, char *text, int line_count,
				char **result);

/*Returns a 2D-array of chars. Each array resembles on line from the input
string text. Similar to split for \n. Except that split will not output empty
lines if several newlines follow each other. This function will.*/
char	**f_splitlines(t_main *main, char *text)
{
	int		line_count;
	char	**result;

	line_count = f_char_count(text, '\n') + 1;
	if (line_count == 0)
		return (NULL);
	result = f_gc_malloc(main, (line_count + 1) * sizeof(void *));
	if (result == NULL)
		return (NULL);
	if (sf_fill_array(main, text, line_count, result) == 1)
		return (NULL);
	return (result);
}

static int	sf_fill_array(t_main *main, char *pos, int line_count,
		char **result)
{
	size_t	len;
	int		i;

	i = 0;
	while (i < line_count - 1)
	{
		len = f_strchr(pos, '\n') - pos;
		result[i] = f_gc_malloc(main, (len + 1) * sizeof(char));
		f_memcpy(result[i], pos, len);
		result[i][len] = '\0';
		pos = f_strchr(pos, '\n') + 1;
		i++;
	}
	len = f_strchr(pos, '\0') - pos;
	result[i] = f_gc_malloc(main, (len + 1) * sizeof(char));
	f_memcpy(result[i], pos, len);
	result[i][len] = '\0';
	result[line_count] = NULL;
	return (0);
}
