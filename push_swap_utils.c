/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:03:15 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/15 00:24:16 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_atoi(char *argv)
{
	int			i;
	long long	j;
	int			resu;

	i = 0;
	j = 1;
	resu = 0;
	while (argv[i])
		i++;
	while (argv[i - 1] >= 48 && argv[i - 1] <= 57 && i - 1 >= 0)
	{
		if (j > 1000000000)
		{
			write(2, "Error 2\n", 8);
			exit(EXIT_FAILURE);
		}
		if (j == 1000000000)
			check_overflow(argv, i, resu);
		resu += (argv[i - 1] - 48) * j;
		j *= 10;
		i--;
	}
	if (i - 1 == 0)
		return (-resu);
	return (resu);
}

void	check_overflow(char *argv, int i, int resu)
{
	if (argv[0] == '-')
	{
		if (((argv[i - 1] - 48) == 2 && resu > 147483648) ||
			(argv[i - 1] - 48) > 2)
		{
			write(2, "Error 2\n", 8);
			exit(EXIT_FAILURE);
		}
	}
	else if (((argv[i - 1] - 48) == 2 && resu > 147483647)
		|| argv[i - 1] - 48 > 2)
	{
		write(2, "Error 2\n", 8);
		exit(EXIT_FAILURE);
	}
}

int	*fill_int_table(int argc, char **argv, int *nbr_table)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	printf("%d\n", argc);
	nbr_table = malloc(sizeof(int) * (argc - 1));
	if (!nbr_table)
	{
		free(nbr_table);
		nbr_table = NULL;
		write(2, "Error 3\n", 8);
		exit(EXIT_FAILURE);
	}
	//*argv++;
	//while (*argv)
	while (argc - j)
	{
		printf("argv : %s\n", argv[j]);
		printf("nbr_table : %d\n", nbr_table[i]);
		nbr_table[i] = ft_atoi(argv[j]);
		//printf("%s\n", *argv);
		printf("argv : %s\n", argv[j]);
		printf("nbr_table : %d\n", nbr_table[i]);
		i++;
		//*argv++;
		j++;
	}
	/* i = 0;
	while (nbr_table[i])
	{
		printf("%d\n", nbr_table[i]);
		i++;
	} */
	/* i = 0;
	while (nbr_table[i])
	{
		printf("%d\n", nbr_table[i]);
		i++;
	} */
	/* printf("%d\n", nbr_table[i + 1]);
	printf("%d\n", nbr_table[i + 2]);
	printf("%d\n", nbr_table[i + 3]);
	printf("%d\n", nbr_table[i + 4]);
	printf("%d\n", nbr_table[i + 5]); */
	/* printf("argv : %s\n", argv[j+ 1]);
	printf("nbr_table : %d\n", nbr_table[i + 1]);
	printf("argv : %s\n", argv[j+ 2]);
	printf("nbr_table : %d\n", nbr_table[i + 2]);
	printf("argv : %s\n", argv[j+ 3]);
	printf("nbr_table : %d\n", nbr_table[i + 3]);
	printf("argv : %s\n", argv[j+ 4]);
	printf("nbr_table : %d\n", nbr_table[i + 4]); */
	return (nbr_table);
}
