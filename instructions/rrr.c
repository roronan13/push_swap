/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:03:21 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/16 17:30:19 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rot_a_rev_rot_b(t_list_element *a_head, t_list_element *b_head)
{
	reverse_rotate(a_head);
	reverse_rotate(b_head);
	write(1, "rrr\n", 4);
}

void	reverse_rotate(t_list_element *head)
{
	t_list_element	*temp_ptr;
	int				int_1;
	int				int_2;

	if (!head)
		return ;
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
}
