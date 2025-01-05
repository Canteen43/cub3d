/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_splitlines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:08:34 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/05 13:23:10 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Static functions:
static int	sf_fill_array(char *text, int line_count, char **result);
static int	sf_free_and_return(char **result, int i);

/*Returns a 2D-array of chars. Each array resembles on line from the input
string text. Similar to split for \n. Except that split will not output empty
lines if several newlines follow each other. This function will.*/
char	**f_splitlines(char *text)
{
	int		line_count;
	char	**result;

	line_count = f_char_count(text, '\n') + 1;
	if (line_count == 0)
		return (NULL);
	result = malloc((line_count + 1) * sizeof(void *));
	if (result == NULL)
		return (NULL);
	if (sf_fill_array(text, line_count, result) == 1)
		return (NULL);
	return (result);
}

static int	sf_fill_array(char *pos, int line_count, char **result)
{
	size_t	len;
	int		i;

	i = 0;
	while (i < line_count)
	{
		len = f_strchr(pos, '\n') - pos;
		result[i] = malloc((len + 1) * sizeof(char));
		if (!result[i])
			sf_free_and_return(result, i);
		f_memcpy(result[i], pos, len);
		result[i][len] = '\0';
		pos = f_strchr(pos, '\n') + 1;
		i++;
	}
	return (0);
}

static int	sf_free_and_return(char **result, int i)
{
	i--;
	while (i >= 0)
		free(result[i]);
	free(result);
	return (1);
}
