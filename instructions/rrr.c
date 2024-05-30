/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:03:21 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/30 20:45:09 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rot_a_rev_rot_b(t_node *a_head, t_node *b_head)
{
	reverse_rotate(a_head);
	reverse_rotate(b_head);
	write(1, "rrr\n", 4);
}

void	reverse_rotate(t_node *head)
{
	t_node			*temp_ptr;
	int				content_1;
	int				content_2;
	int				final_1;
	int				final_2;

	if (!head)
		return ;
	temp_ptr = head->next;
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
		temp_ptr = temp_ptr->next;
	}
	temp_ptr->content = content_1;
	temp_ptr->final = final_1;
	reverse_rotate_group(head);
}

void	reverse_rotate_group(t_node *head)
{
	t_node			*temp_ptr;
	int				group_1;
	int				group_2;

	temp_ptr = head->next;
	group_1 = head->group;
	while (temp_ptr != head)
	{
		group_2 = temp_ptr->group;
		temp_ptr->group = group_1;
		group_1 = group_2;
		temp_ptr = temp_ptr->next;
	}
	temp_ptr->group = group_1;
}
