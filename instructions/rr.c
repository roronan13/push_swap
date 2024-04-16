/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:45:49 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/16 16:55:34 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a_rotate_b(t_list_element *a_head, t_list_element *b_head)
{
	rotate(a_head);
	rotate(b_head);
	write(1, "rr\n", 3);
}

void	rotate(t_list_element *head)
{
	t_list_element	*temp_ptr;
	int				int_1;
	int				int_2;

	temp_ptr = head->previous;
	int_1 = head->content;
	while (temp_ptr != head)
	{
		int_2 = temp_ptr->content;
		temp_ptr->content = int_1;
		int_1 = int_2;
		temp_ptr = temp_ptr->previous;
	}
	temp_ptr->content = int_1;
	temp_ptr = NULL;
}
