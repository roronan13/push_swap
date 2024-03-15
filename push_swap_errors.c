/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:11:22 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/15 16:01:19 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	check_errors(int argc, char **argv)
{
	check_params(argc, argv);
	check_number(argc, argv);
	check_long(argc, argv);
	check_twice(argc, argv);
}

void	check_params(int argc, char **argv)
{
	if (argc <= 1 && argv[1] == NULL)
		exit(EXIT_SUCCESS);
}

void	check_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] >= 48 && argv[i][j] <= 57)
				j++;
			else
			{
				write(2, "Error 1\n", 8);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

void	check_long(int argc, char **argv)
{
	//long long	nbr;
	int	i;

	i = 1;
	while (i < argc)
	{
		//nbr = ft_atoi(argv[i]);
		ft_atoi(argv[i]);
		//printf("retour : %lld\n", nbr);
		/* if (nbr < -2147483648 || nbr > 2147483647)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		} */
		i++;
	}
}

void	check_twice(int argc, char **argv)
{
	int	*nbr_table;
	int	i;
	int	j;

	i = 0;
	nbr_table = fill_int_table(argc, argv, nbr_table);
	while (nbr_table[i] > INT_MIN && i <= (argc - 3))
	{
		printf("%d\n", nbr_table[i]);
		j = i + 1;
		while (nbr_table[j])
		{
			if (nbr_table[i] == nbr_table[j])
			{
				write(2, "Error 3\n", 8);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
