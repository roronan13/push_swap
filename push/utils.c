/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:57:39 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/04 16:58:56 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr_dest;
	char	*ptr_src;

	i = 0;
	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (ptr_dest);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	a;

	a = ft_strlen(s);
	ptr = malloc(sizeof(char) * (a + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, a + 1);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	long unsigned int	i;
	char				*ptr;
	unsigned char		a;

	i = 0;
	ptr = (char *)s;
	a = (unsigned char)c;
	if (a == '\0')
	{
		while (s[i])
			i++;
		ptr = (char *)&s[i];
		return (ptr);
	}
	while (s[i] != a && s[i])
		i++;
	if (s[i] == a)
	{
		ptr = (char *)&s[i];
		return (ptr);
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
