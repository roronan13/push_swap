/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_swap_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:32:12 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/16 16:35:42 by rpothier         ###   ########.fr       */
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
	int				temp_int;
	t_list_element	*temp_ptr;

	if (!head || head->next == head)
		return ;
	temp_ptr = head->next;
	temp_int = temp_ptr->content;
	temp_ptr->content = head->content;
	head->content = temp_int;
	temp_ptr = NULL;
}
