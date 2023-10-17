/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:00:20 by kafortin          #+#    #+#             */
/*   Updated: 2023/10/17 19:00:35 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_part(void *dest, const void *src, int start, int end)
{
	size_t	a;

	a = 0;
	if (!dest && !src)
		return (NULL);
	while (start <= end)
	{
		((char *)dest)[a] = ((char *)src)[start];
		start++;
		a++;
	}
	return (dest);
}
