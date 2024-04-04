/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:19:12 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/05 00:35:59 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_list_element *head)
{
	t_list_element	*temp_ptr;
	int				int_1;
	int				int_2;

	temp_ptr = head->next;
	int_1 = head->content;
	while (temp_ptr != head)
	{
		int_2 = temp_ptr->content;
		temp_ptr->content = int_1;
		int_1 = int_2;
		temp_ptr = temp_ptr->next;
	}
	temp_ptr->content = int_1;
	temp_ptr = NULL;
	write(1, "rra\n", 4);
}