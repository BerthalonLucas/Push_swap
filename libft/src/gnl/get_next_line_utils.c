/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:44:11 by lucas             #+#    #+#             */
/*   Updated: 2024/03/14 00:25:58 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str || str[i] == '\0')
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero_gnl(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*mm_gnl(char *dest, char *src, size_t n)
{
	size_t	i;

	if (dest > src)
		while (n--)
			dest[n] = src[n];
	else
	{
		i = 0;
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}

size_t	ft_strlcpy_gnl(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i < size - 1 && size != 0 && src[i] != '\n')
	{
		dst[i] = src[i];
		++i;
	}
	if (size)
		dst[i] = '\0';
	return (ft_strlen_gnl(src));
}

size_t	ft_strlcat_gnl(char *dest, char *src, size_t size, t_gnl *g)
{
	size_t	i;
	size_t	r;
	size_t	src_len;
	size_t	dest_len;

	i = 0;
	r = 0;
	src_len = BUFFER_SIZE;
	dest_len = ft_strlen_gnl(dest);
	while (dest[i])
		i++;
	if (i >= size)
		return (src_len + size);
	while (src[r] && (&src[r - 1] != g->n_ptr))
	{
		if (i == size - 1)
			break ;
		dest[i] = src[r];
		i++;
		r++;
	}
	dest[i] = '\0';
	if (size <= (src_len + ft_strlen_gnl(dest)))
		return (dest_len + src_len);
	return (ft_strlen_gnl(dest));
}
