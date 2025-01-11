/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:11:19 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/11 18:11:45 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Returns pointer to substring with index. Returns NULL if there is no
substring with index. Can also be used to count number of substrings.*/
static const char	*index_substr(const char *str, int index, char dlm)
{
	int	char_sctn;

	char_sctn = 0;
	while (*str && index > 0)
	{
		if (char_sctn == 1 && *str == dlm)
			index--;
		if (*str != dlm)
			char_sctn = 1;
		if (*str == dlm)
			char_sctn = 0;
		str++;
	}
	while (*str && *str == dlm)
		str++;
	if (!*str)
		return (NULL);
	return (str);
}

/* Counts length of substring. Str is set to first char of substring with
index i. Then bytes are counted until delimiter or Null is found.*/
static int	substr_len(char const *str, char dlm, int i)
{
	int	cnt;

	str = index_substr(str, i, dlm);
	cnt = 0;
	while (*str != dlm && *str)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

/* Copies from str to sub. Str is set to location of first char of substring of
 index i. Then str is written to sub until dlm or null is found.*/
static void	substr_cpy(char const *str, char dlm, int i, char *sub)
{
	str = index_substr(str, i, dlm);
	while (*str != dlm && *str)
	{
		*sub++ = *str++;
	}
	*sub = '\0';
}

char	**f_split(char const *s, char c)
{
	int		sub_cnt;
	char	**ptr;
	int		i;

	sub_cnt = 0;
	while (index_substr(s, sub_cnt, c))
		sub_cnt++;
	ptr = f_gc_malloc(main, (sub_cnt + 1) * sizeof(void *));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < sub_cnt)
	{
		ptr[i] = f_gc_malloc(main, (substr_len(s, c, i) + 1) * sizeof(char));
		if (ptr[i] == NULL)
		{
			f_free_split(ptr);
			return (NULL);
		}
		substr_cpy(s, c, i, ptr[i]);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
