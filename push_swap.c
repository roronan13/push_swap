/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:35:38 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/20 18:29:50 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list_element	**nbr_list;
	
	*nbr_list = NULL;
	check_errors(argc, argv);
	nbr_list = malloc(sizeof(t_list_element));
	nbr_list = create_list(argc, argv, nbr_list);
	return (0);
}

t_list_element	**create_list(int argc, char **argv, t_list_element **nbr_list)
{
	t_list_element	*new_element;

	new_element = *nbr_list;
}
