/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:03:15 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/08 18:31:18 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(char *argv)
{
	int			i;
	int			j;
	long int	resu;

	i = 0;
	j = 1;
	if (argv[i] == '-')
		i++;
	while (argv[i] >= 0 && argv[i] <= 9)
		i++;
	while (argv[i - 1] >= 0 && argv[i - 1] <= 9 && i - 1 >= 0)
	{
		resu += (argv[i - 1] - 48) * j;
		j *= 10;
		i--;
	}
	if (argv[i - 1] == '-')
		return (-resu);
	return (resu);
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
