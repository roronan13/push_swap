/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:03:15 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/08 17:18:58 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *argv)
{
	int	i;
	int	j;
	int	resu;

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
