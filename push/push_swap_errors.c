/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:11:22 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/30 21:18:00 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**check_errors(int *argc, char **argv, char **list)
{
	char	*first_list;
	int		i;
	
	i = 0;
	check_params(*argc, argv);
	if (*argc == 2)
	{
		if (!make_malloc(first_list = ft_strtrim(argv[1], "\"")))
			return (NULL);
		if (!make_malloc(list = ft_split(first_list, ' ')))
		{
			free(first_list);
			return (NULL);
		}
		free(first_list);
	}
	else
	{
		if (!make_malloc(list = malloc(sizeof(char*) * *argc)))
			return (NULL);
		while (argv[i + 1])
		{
			list[i] = ft_strdup(argv[i + 1]);
			if (!list[i])
			{
				ft_free(list);
				return (NULL);
			}
			i++;
		}
		list[i] = NULL;
	}
	i = tab_size(list);
	*argc = i;
	if (!check_number(i, list))
	{
		ft_free(list);
		return (NULL);
	}
	check_long(i, list);
	if (!check_twice(i, list))
	{
		ft_free(list);
		return (NULL);
	}
	return (list);
}

void	check_params(int argc, char **argv)
{
	if (argc <= 1 && argv[1] == NULL)
		exit(EXIT_SUCCESS);
}

int	check_number(int size, char **list)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		if (list[i][j] == '-' || list[i][j] == '+')
			j++;
		while (list[i][j])
		{
			if (list[i][j] >= 48 && list[i][j] <= 57)
				j++;
			else
			{
				write(2, "Error5\n", 7);
				//exit(EXIT_FAILURE);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

void	check_long(int size, char **list)
{
	int	i;

	i = 0;
	(void)size;
	while (list[i])
	{
		//printf("%s\n", argv[i]);
		ft_atoi(list[i], list);
		i++;
	}
}

int	check_twice(int size, char **list)
{
	int	*nbr_table;
	int	i;
	int	j;

	i = 0;
	nbr_table = fill_int_table(size, list);
	if (!nbr_table)
		return (0);
	while (i <= (size - 2))
	{
		j = i + 1;
		while (j <= (size - 1))
		{
			if (nbr_table[i] == nbr_table[j])
			{
				write(2, "Error6\n", 7);
				free(nbr_table);
				//exit(EXIT_FAILURE);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(nbr_table);
	return (1);
}
