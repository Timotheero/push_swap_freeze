/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:20:23 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/21 14:33:24 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	digit;

	i = 0;
	negative = 1;
	digit = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = (digit * 10) + (str[i] - '0');
		i++;
	}
	return (digit * negative);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ndst;
	unsigned const char	*nsrc;
	int					i;

	if ((dst == NULL && src == NULL))
		return (NULL);
	ndst = (unsigned char *)dst;
	nsrc = (const unsigned char *)src;
	if (nsrc < ndst && nsrc + len > ndst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			ndst[i] = nsrc[i];
		}
	}
	else
	{
		while (len--)
			*ndst++ = *nsrc++;
	}
	return (dst);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;

	lensrc = 0;
	i = 0;
	while (src[lensrc] != '\0')
		lensrc++;
	if (dstsize == 0)
		return (lensrc);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (lensrc);
}
