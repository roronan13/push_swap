/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:03:15 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/30 22:10:31 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(char *list, char **ptr_list)
{
	int			i;
	long long	j;
	int			resu;

	i = 0;
	j = 1;
	resu = 0;
	while (list[i])
		i++;
	while (i - 1 >= 0 && list[i - 1] >= 48 && list[i - 1] <= 57)
	{
		if (j > 1000000000 && list[i - 1] != '0')
		{
			write(2, "Error1\n", 7);
			exit((ft_free(ptr_list), EXIT_FAILURE));
		}
		if (j == 1000000000)
			check_overflow(list, i, resu, ptr_list);
		resu += (list[i - 1] - 48) * j;
		j *= 10;
		i--;
	}
	if (list[0] == '-')
		return (-resu);
	return (resu);
}

void	check_overflow(char *list, int i, int resu, char **ptr_list)
{
	if (list[0] == '-')
	{
		if (((list[i - 1] - 48) == 2 && resu > 147483648)
			|| (list[i - 1] - 48) > 2)
		{
			write(2, "Error2\n", 7);
			ft_free(ptr_list);
			exit(EXIT_FAILURE);
		}
	}
	else if (((list[i - 1] - 48) == 2 && resu > 147483647)
		|| list[i - 1] - 48 > 2)
	{
		write(2, "Error3\n", 7);
		ft_free(ptr_list);
		exit(EXIT_FAILURE);
	}
}

int	*fill_int_table(int size, char **list)
{
	int	i;
	int	*nbr_table;

	i = 0;
	nbr_table = malloc(sizeof(int) * size);
	if (!nbr_table)
		return (NULL);
	while (list[i])
	{
		nbr_table[i] = ft_atoi(list[i], NULL);
		i++;
	}
	return (nbr_table);
}

int	tab_size(char **tab)
{
	int	i;
	
	i = 0;
	if (!tab || !*tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}


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
	//ptr = malloc(sizeof(char) * a + 1);
	ptr = malloc(sizeof(char) * (a + 1));
	if (!ptr)
		return (NULL);
	//printf("ptr 1 : %s\n", ptr);
	ft_memcpy(ptr, s, a + 1);
	//printf("ptr 2 : %s\n", ptr);
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
