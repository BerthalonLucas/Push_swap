/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:22:15 by lberthal          #+#    #+#             */
/*   Updated: 2024/03/14 01:23:01 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	r;
	size_t	src_len;
	size_t	dest_len;

	if (!dest || !src)
		return (0);
	i = 0;
	r = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	while (dest[i])
		i++;
	if (i >= size)
		return (src_len + size);
	while (src[r])
	{
		if (i == size - 1)
			break ;
		dest[i++] = src[r++];
	}
	dest[i] = '\0';
	if (size <= (src_len + ft_strlen(dest)))
		return (dest_len + src_len);
	return (ft_strlen(dest));
}
