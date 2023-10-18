/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:01:11 by kafortin          #+#    #+#             */
/*   Updated: 2023/10/17 19:01:44 by kafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_part(char *src, int start, int end)
{
	int		len;
	char	*copy;

	len = end - start + 1;
	copy = ft_calloc(sizeof(char), len + 1);
	if (copy == NULL)
		return (NULL);
	ft_memcpy_part(copy, src, start, end);
	return (copy);
}
