/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:11:22 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/07 19:29:49 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_errors(int argc, char **argv)
{
	check_params(argc, argv);
	check_number(argc, argv);
}

void	check_params(int argc, char **argv)
{
	if (argc <= 1 && argv[1] == NULL)
		exit(EXIT_SUCCESS);
}

void	check_number(int argc, char **argv)
{
	
}