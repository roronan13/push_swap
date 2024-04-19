/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:32:12 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/19 02:01:11 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a_swap_b(t_list_element *a_head, t_list_element *b_head)
{
	swap(a_head);
	swap(b_head);
	write(1, "ss\n", 3);
}

void	swap(t_list_element *head)
{
	int				temp_content;
	int				temp_final;
	t_list_element	*temp_ptr;

	if (!head || head->next == head)
		return ;
	temp_ptr = head->next;
	temp_content = temp_ptr->content;
	temp_final = temp_ptr->final;
	temp_ptr->content = head->content;
	temp_ptr->final = head->final;
	head->content = temp_content;
	head->final = temp_final;
	temp_ptr = NULL;
}
