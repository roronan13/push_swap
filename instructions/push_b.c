/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:51:55 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/04 17:17:43 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b(t_node **a_head, t_node **b_head)
{
	t_node	*temp_ptr;

	if (!*a_head)
		return ;
	if (!*b_head)
		new_b_list(a_head, b_head);
	else
		add_to_b_list(a_head, b_head, &temp_ptr);
	if ((*a_head)->next == *a_head)
	{
		free(*a_head);
		write((*a_head = NULL, 1), "pb\n", 3);
		return ;
	}
	temp_ptr = (*a_head)->next;
	while (temp_ptr != *a_head)
	{
		temp_ptr->index = temp_ptr->index - 1;
		temp_ptr = temp_ptr->next;
	}
	(*a_head)->previous->next = (*a_head)->next;
	(*a_head)->next->previous = (*a_head)->previous;
	free((temp_ptr = *a_head, *a_head = (*a_head)->next, temp_ptr));
	temp_ptr = NULL;
	write(1, "pb\n", 3);
}

void	new_b_list(t_node **a_head, t_node **b_head)
{
	*b_head = malloc(sizeof(t_node));
	if (!*b_head)
	{
		clean(*a_head);
		exit(EXIT_FAILURE);
	}
	(*b_head)->content = (*a_head)->content;
	(*b_head)->final = (*a_head)->final;
	(*b_head)->group = (*a_head)->group;
	(*b_head)->index = 1;
	(*b_head)->next = *b_head;
	(*b_head)->previous = *b_head;
}

void	add_to_b_list(t_node **a_head, t_node **b_head, t_node **ptr)
{
	*ptr = malloc(sizeof(t_node));
	if (!*ptr)
	{
		clean(*a_head);
		clean(*b_head);
		exit(EXIT_FAILURE);
	}
	(*b_head)->previous = *ptr;
	(*ptr)->next = *b_head;
	(*ptr)->previous = ft_lst_last(*b_head);
	(*ptr)->content = (*a_head)->content;
	(*ptr)->final = (*a_head)->final;
	(*ptr)->group = (*a_head)->group;
	(*ptr)->index = 1;
	(ft_lst_last(*b_head))->next = *ptr;
	while (*b_head != *ptr)
	{
		(*b_head)->index = (*b_head)->index + 1;
		*b_head = (*b_head)->next;
	}
}
