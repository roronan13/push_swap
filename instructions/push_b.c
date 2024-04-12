/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:51:55 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/12 15:18:33 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b(t_list_element **a_head, t_list_element **b_head)
{
	t_list_element	*temp_ptr;
	if (!*a_head)
		return ;
	if (!*b_head)
		new_b_list(a_head, b_head);
	else
		add_to_b_list(a_head, b_head, &temp_ptr);
	if ((*a_head)->next == *a_head)
	{
		free(*a_head);
		*a_head = NULL;
		write(1, "pb\n", 3);
		return ;
	}
	(*a_head)->previous->next = (*a_head)->next;
	(*a_head)->next->previous = (*a_head)->previous;
	temp_ptr = *a_head;
	*a_head = (*a_head)->next;
	free(temp_ptr);
	temp_ptr = NULL;
	write(1, "pb\n", 3);
}

void	new_b_list(t_list_element **a_head, t_list_element **b_head)
{
	make_malloc(*b_head = malloc(sizeof(t_list_element)));
	(*b_head)->content = (*a_head)->content;
	(*b_head)->next = *b_head;
	(*b_head)->previous = *b_head;
}

void	add_to_b_list(t_list_element **a_head, t_list_element **b_head, t_list_element **temp_ptr)
{
	make_malloc(*temp_ptr = malloc(sizeof(t_list_element)));
	(*b_head)->previous = *temp_ptr;
	(*temp_ptr)->next = *b_head;
	(*temp_ptr)->previous = ft_lst_last(*b_head);
	(*temp_ptr)->content = (*a_head)->content;
	(ft_lst_last(*b_head))->next = *temp_ptr;
	*b_head = *temp_ptr;
}
