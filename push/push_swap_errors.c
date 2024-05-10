/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:11:22 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/10 15:39:26 by rpothier         ###   ########.fr       */
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
		make_malloc(first_list = ft_strtrim(argv[1], "\""));
		make_malloc(list = ft_split(first_list, ' '));
		free(first_list);
	}
	else
	{
		make_malloc(list = malloc(sizeof(char*) * *argc));
		while (argv[i + 1])
		{
			list[i] = ft_strdup(argv[i + 1]);
			if (!list[i])
				ft_free(list);
			i++;
		}
		list[i] = NULL;
	}
	i = 0;
	while(list[i])
	{
		printf("%s\n", list[i]);
		i++;
	}
	i = tab_size(list);
	*argc = i;
	check_number(i, list);
	check_long(i, list);
	check_twice(i, list);
	return (list);
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

	i = 0;
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
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

void	check_long(int argc, char **argv)
{
	int	i;

	i = 0;
	(void)argc;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		ft_atoi(argv[i]);
		i++;
	}
}

void	check_twice(int argc, char **argv)
{
	int	*nbr_table;
	int	i;
	int	j;

	i = 0;
	nbr_table = fill_int_table(argc, argv);
	while (i <= (argc - 2))
	{
		j = i + 1;
		while (j <= (argc - 1))
		{
			if (nbr_table[i] == nbr_table[j])
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	free(nbr_table);
	nbr_table = NULL;
}
