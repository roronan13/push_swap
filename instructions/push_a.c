/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:55:14 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/12 16:03:13 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_list_element **a_head, t_list_element **b_head)
{
	t_list_element	*temp_ptr;
	if (!*b_head)
		return ;
	if (!*a_head)
		new_a_list(a_head, b_head);
	else
		add_to_a_list(a_head, b_head, &temp_ptr);
	if ((*b_head)->next == *b_head)
	{
		free(*b_head);
		*b_head = NULL;
		write(1, "pa\n", 3);
		return ;
	}
	(*b_head)->previous->next = (*b_head)->next;
	(*b_head)->next->previous = (*b_head)->previous;
	temp_ptr = *b_head;
	*b_head = (*b_head)->next;
	free(temp_ptr);
	temp_ptr = NULL;
	write(1, "pa\n", 3);
}

void	new_a_list(t_list_element **a_head, t_list_element **b_head)
{
	make_malloc(*a_head = malloc(sizeof(t_list_element)));
	(*a_head)->content = (*b_head)->content;
	(*a_head)->next = *a_head;
	(*a_head)->previous = *a_head;
}

void	add_to_a_list(t_list_element **a_head, t_list_element **b_head, t_list_element **temp_ptr)
{
	make_malloc(*temp_ptr = malloc(sizeof(t_list_element)));
	(*a_head)->previous = *temp_ptr;
	(*temp_ptr)->next = *a_head;
	(*temp_ptr)->previous = ft_lst_last(*a_head);
	(*temp_ptr)->content = (*b_head)->content;
	(ft_lst_last(*a_head))->next = *temp_ptr;
	*a_head = *temp_ptr;
}
