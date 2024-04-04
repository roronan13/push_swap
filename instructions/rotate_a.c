/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:52:42 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/04 22:05:11 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_list_element *head)
{
	t_list_element	*temp_ptr;
	int				temp_int;

	temp_ptr = head;
	temp_int = temp_ptr->previous->content;
	while (temp_ptr->previous != head)
	{
		temp_ptr->previous->content = temp_int;
		temp_ptr = temp_ptr->previous;
	}
}
