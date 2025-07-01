/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 14:33:26 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/07/01 00:06:40 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;
	int		len;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	dst = (char *)malloc((sizeof(char)) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (len > i)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&dst[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[0] != 0)
	{
		s++;
		len++;
	}
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	size_t			total_size;
	unsigned char	*ptr;

	total_size = count * size;
	i = 0;
	if (count > 0 && total_size / count > size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			count;
	unsigned char	*bb;

	bb = b;
	count = 0;
	while (len != 0)
	{
		bb[count] = (unsigned char)c;
		len--;
		count++;
	}
	return (b);
}
