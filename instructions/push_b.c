/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:51:55 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/11 18:56:31 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b(t_list_element **a_head, t_list_element **b_head)
{
	t_list_element	*temp_ptr;
	t_list_element	*temp_ptr_2;
	if (!*a_head)
		return ;
	if (!*b_head)
	{
		make_malloc(*b_head = malloc(sizeof(t_list_element)));
		(*b_head)->content = (*a_head)->content;
		(*b_head)->next = *b_head;
		(*b_head)->previous = *b_head;
	}
	else
	{
		make_malloc(temp_ptr = malloc(sizeof(t_list_element)));
		temp_ptr_2 = ft_lst_last(*b_head);
		(*b_head)->previous = temp_ptr;
		temp_ptr->next = *b_head;
		temp_ptr->previous = temp_ptr_2;
		temp_ptr->content = (*a_head)->content;
		temp_ptr_2->next = temp_ptr;
		*b_head = temp_ptr;
	}
	(*a_head)->previous->next = (*a_head)->next;
	(*a_head)->next->previous = (*a_head)->previous;
	temp_ptr = *a_head;
	*a_head = (*a_head)->next;
	free(temp_ptr);
	temp_ptr = NULL;
}
