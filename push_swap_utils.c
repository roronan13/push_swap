/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:03:15 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/13 21:17:04 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

long long	ft_atoi(char *argv)
{
	int				i;
	long long		j;
	long long		resu;

	i = 0;
	j = 1;
	resu = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i])
		i++;
	while (argv[i - 1] >= 48 && argv[i - 1] <= 57 && i - 1 >= 0)
	{
		/* if ((j == 1000000000 && (argv[i - 1] - 48) >= 2) && resu > 147483647)
		{
			if 
		} */
		if (j > 1000000000)
		{
			write(2, "Error2\n", 7);
			exit(EXIT_FAILURE);
		}
		if (j == 1000000000)
		{
			check_overflow(argv, i, j, resu);
			/* if (((argv[i - 1] - 48) == 2 && resu > 147483647) ||
				(argv[i - 1] - 48) > 2)
				return (0); */
		}
		/* if ((long long)((long long)resu + (long long)((argv[i - 1] - 48) * j)) > INT_MAX || 
			resu + ((argv[i - 1] - 48) * j) < INT_MIN)
			return (0); */
		/* if ((long long)((argv[i - 1] - 48) * j) > INT_MAX - resu)
			return (0); */
		resu += (argv[i - 1] - 48) * j;
		/* if ((long long)resu > INT_MAX)
			return (0); */
		j *= 10;
		i--;
		printf("%lld\n", resu);
	}
	if (argv[i - 1] == '-')
		return (-resu);
	return (resu);
}

void	check_overflow(char *argv, int i, long long j, long long resu)
{
	if (argv[0] == '-')
	{
		if (((argv[i - 1] - 48) == 2 && resu > 147483648) ||
			(argv[i - 1] - 48) > 2)
		{
			write(2, "Error2\n", 7);
			exit(EXIT_FAILURE);
		}
	}
	else if (((argv[i - 1] - 48) == 2 && resu > 147483647)
		|| argv[i - 1] - 48 > 2)
	{
		write(2, "Error2\n", 7);
		exit(EXIT_FAILURE);
	}
}

int	*fill_int_table(int argc, char **argv, int *nbr_table)
{
	int	i;

	i = 0;
	nbr_table = malloc(sizeof(int) * (argc - 1));
	if (!nbr_table)
	{
		free(nbr_table);
		nbr_table = NULL;
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	*argv++;
	while (*argv)
	{
		nbr_table[i] = ft_atoi(*argv);
		i++;
		*argv++;
	}
	return (nbr_table);
}
