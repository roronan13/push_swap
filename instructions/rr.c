/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:45:49 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/30 14:29:57 by rpothier         ###   ########.fr       */
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
	int				content_1;
	int				content_2;
	int				final_1;
	int				final_2;
	int				group_1;
	int				group_2;
	int				i;

	i = 0;
	if (!head)
		return ;

		
	temp_ptr = head->previous;
	content_1 = head->content;
	final_1 = head->final;
	while (temp_ptr != head)
	{
		content_2 = temp_ptr->content;
		final_2 = temp_ptr->final;
		temp_ptr->content = content_1;
		temp_ptr->final = final_1;
		content_1 = content_2;
		final_1 = final_2;
		temp_ptr = temp_ptr->previous;
	}
	temp_ptr->content = content_1;
	temp_ptr->final = final_1;
	temp_ptr = NULL;


	temp_ptr = head;
	content_1 = head->content;
	final_1 = head->final;
	group_1 = head->group;
	while (i++ < list_size(head))
	{
		content_2 = temp_ptr->content;
		final_2 = temp_ptr->final;
		group_2 = temp_ptr->group;
		temp_ptr->content = content_1;
		temp_ptr->final = final_1;
		temp_ptr->group = group_1;
		content_1 = content_2;
		final_1 = final_2;
		group_1 = group_2;
		temp_ptr = temp_ptr->previous;
	}
}
