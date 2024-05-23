/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:55:14 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/23 15:40:28 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(node **a_head, node **b_head)
{
	node	*temp_ptr;
	
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
	temp_ptr = (*b_head)->next;
	while (temp_ptr != *b_head)
	{
		temp_ptr->index = temp_ptr->index - 1;
		temp_ptr = temp_ptr->next;
	}
	(*b_head)->previous->next = (*b_head)->next;
	(*b_head)->next->previous = (*b_head)->previous;
	temp_ptr = *b_head;
	*b_head = (*b_head)->next;
	free(temp_ptr);
	temp_ptr = NULL;
	write(1, "pa\n", 3);
}

void	new_a_list(node **a_head, node **b_head)
{
	if (!make_malloc(*a_head = malloc(sizeof(node))))
	{
		clean(*b_head);
		exit(EXIT_FAILURE);
	}
	(*a_head)->content = (*b_head)->content;
	(*a_head)->final = (*b_head)->final;
	(*a_head)->group = (*b_head)->group;
	(*a_head)->index = 1;
	(*a_head)->next = *a_head;
	(*a_head)->previous = *a_head;
}

void	add_to_a_list(node **a_head, node **b_head, node **temp_ptr)
{
	if (!make_malloc(*temp_ptr = malloc(sizeof(node))))
	{
		clean(*a_head);
		clean(*b_head);
		exit(EXIT_FAILURE);
	}
	(*a_head)->previous = *temp_ptr;
	(*temp_ptr)->next = *a_head;
	(*temp_ptr)->previous = ft_lst_last(*a_head);
	(*temp_ptr)->content = (*b_head)->content;
	(*temp_ptr)->final = (*b_head)->final;
	(*temp_ptr)->group = (*b_head)->group;
	(*temp_ptr)->index = 1;
	(ft_lst_last(*a_head))->next = *temp_ptr;
	while (*a_head != *temp_ptr)
	{
		(*a_head)->index = (*a_head)->index + 1;
		*a_head = (*a_head)->next;
	}
	//*a_head = *temp_ptr;
}
