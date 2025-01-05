/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:33:51 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/05 12:47:23 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*f_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)dest[i] = *(unsigned char *)src[i];
		i++;
	}
	return (dest);
}
