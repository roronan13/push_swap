/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:03:15 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/04 17:18:35 by rpothier         ###   ########.fr       */
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
			write(2, "Error\n", 6);
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
			write(2, "Error\n", 6);
			ft_free(ptr_list);
			exit(EXIT_FAILURE);
		}
	}
	else if (((list[i - 1] - 48) == 2 && resu > 147483647)
		|| list[i - 1] - 48 > 2)
	{
		write(2, "Error\n", 6);
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
