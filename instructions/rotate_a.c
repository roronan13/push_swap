/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:52:42 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/04 22:55:58 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_list_element *head)
{
	t_list_element	*temp_ptr;
	int				int_1;
	int				int_2;

	temp_ptr = head->previous;
	int_1 = head->content;
	while (temp_ptr->previous != head)
	{
		int_2 = temp_ptr->content;
		temp_ptr->content = int_1;
		int_2 = temp_ptr->previous->content;
		temp_ptr = temp_ptr->previous;
	}
}
