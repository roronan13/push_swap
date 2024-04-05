/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:51:55 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/05 06:09:37 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b(t_list_element **a_head, t_list_element **b_head)
{
	t_list_element	*temp_ptr;
	if (!*b_head)
	{
		printf("test 1\n");
		make_malloc(*b_head = malloc(sizeof(t_list_element)));
		(*b_head)->content = (*a_head)->content;
		(*b_head)->next = *b_head;
		(*b_head)->previous = *b_head;
		(*a_head)->previous->next = (*a_head)->next;
		printf("first : %d\n", (*a_head)->previous->next->content);
		(*a_head)->next->previous = (*a_head)->previous;
		//temp_ptr = *a_head;
		*a_head = (*a_head)->next;
		printf("hey %d\n", (*a_head)->content);
		//free(temp_ptr);
		temp_ptr = NULL;
	}
	printf("%d\n", (*a_head)->content);
	printf("%d\n", (*a_head)->previous->content);
	printf("%d\n", (*a_head)->next->content);
	temp_ptr = (*a_head)->previous;
	printf("%d\n", temp_ptr->content);
	printf("%d\n", temp_ptr->next->content);
	printf("%d\n", (*a_head)->previous->next->content);
	printf("%d\n", (*a_head)->previous->previous->content);
}
