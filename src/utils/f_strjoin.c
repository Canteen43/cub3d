/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:43:22 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/11 18:11:45 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*f_strjoin(char const *s1, char const *s2)
{
	size_t	size_needed;
	char	*s3;

	size_needed = f_strlen(s1) + f_strlen(s2) + 1;
	s3 = f_gc_malloc(main, size_needed * sizeof(char));
	if (!s3)
		return (NULL);
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	*s3 = '\0';
	s3 -= (size_needed - 1);
	return (s3);
}
