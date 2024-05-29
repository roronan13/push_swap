/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:57:26 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/29 23:17:41 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_count(char const *s, char c)
{
	long unsigned int	i;
	size_t				j;

	i = 0;
	j = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static char	*ft_fill(const char *s, char c, size_t j)
{
	char		*ptr;
	const char	*ptr2;
	size_t		i;

	i = 0;
	if (ft_strlen(s) == 0)
		return (NULL);
	while (s[j] && s[j] != c)
	{
		j++;
		i++;
	}
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ptr2 = &s[j - i];
	ft_strlcpy(ptr, ptr2, i + 1);
	return (ptr);
}

char	**ft_free(char **ptr)
{
	long unsigned int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (i < ft_count(s, c))
	{
		while (s[j] == c)
			j++;
		ptr[i] = ft_fill(s, c, j);
		if (!ptr[i])
			return (ft_free(ptr));
		while (s[j] != c && s[j])
			j++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	ptr = malloc(sizeof(char) * (j - i + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[i], j - i + 1);
	return (ptr);
}