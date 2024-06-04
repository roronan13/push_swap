/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:50:21 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/04 16:51:06 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_err_one_arg(char **first_list, char **argv, char ***list)
{
	*first_list = ft_strtrim(argv[1], "\"");
	if (!*first_list)
		return (0);
	*list = ft_split(*first_list, ' ');
	if (!*list)
		return (free(*first_list), 0);
	free(*first_list);
	return (1);
}

int	check_errors_more_args(char ***list, char **argv, int *argc)
{
	int	i;

	i = 0;
	*list = malloc(sizeof(char*) * *argc);
	if (!*list)
		return (0);
	while (argv[i + 1])
	{
		(*list)[i] = ft_strdup(argv[i + 1]);
		if (!(*list)[i])
			return (ft_free(*list), 0);
		i++;
	}
	(*list)[i] = NULL;
	return (1);
}
