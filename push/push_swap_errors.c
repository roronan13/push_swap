/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:11:22 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/04 16:53:32 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**check_errors(int *argc, char **argv, char **list)
{
	char	*first_list;

	check_params(*argc, argv);
	if (*argc == 2)
	{
		if (!check_err_one_arg(&first_list, argv, &list))
			return (NULL);
	}
	else
	{
		if (!check_errors_more_args(&list, argv, argc))
			return (NULL);
	}
	*argc = tab_size(list);
	if (!check_number(*argc, list))
		return (ft_free(list), NULL);
	check_long(*argc, list);
	if (!check_twice(*argc, list))
		return (ft_free(list), NULL);
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
				write(2, "Error\n", 6);
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
				write(2, "Error\n", 6);
				free(nbr_table);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(nbr_table);
	return (1);
}
