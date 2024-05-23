/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:32:12 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/23 15:42:14 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a_swap_b(node *a_head, node *b_head)
{
	swap(a_head);
	swap(b_head);
	write(1, "ss\n", 3);
}

void	swap(node *head)
{
	int				temp_content;
	int				temp_final;
	int				temp_group;
	node	*temp_ptr;

	if (!head || head->next == head)
		return ;
	temp_ptr = head->next;
	temp_content = temp_ptr->content;
	temp_final = temp_ptr->final;
	temp_group = temp_ptr->group;
	temp_ptr->content = head->content;
	temp_ptr->final = head->final;
	temp_ptr->group = head->group;
	head->content = temp_content;
	head->final = temp_final;
	head->group = temp_group;
	temp_ptr = NULL;
}
