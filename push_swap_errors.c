/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:11:22 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/08 17:37:24 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (j >= 0 && j <= 9)
				j++;
			else
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

void	check_long(int argc, char **argv)
{
	long int	nbr;
	
	*argv++;
	while (*argv)
	{
		nbr = ft_atoi(*argv);
		if (nbr < -2147483648 || nbr > 2147483647)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		*argv++;
	}
}

void	check_twice(int argc, char **argv)
{
	
}