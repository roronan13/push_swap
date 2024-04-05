/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:51:55 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/05 04:03:07 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b(t_list_element *a_head, t_list_element *b_head)
{
	//t_list_element	*temp_ptr;
	//printf("allo4\n");
	if (!b_head)
	{
		make_malloc(b_head = malloc(sizeof(t_list_element)));
		b_head->content = a_head->content;
		b_head->next = b_head;
		b_head->previous = b_head;
		a_head->previous->next = a_head->next;
		a_head->next->previous = a_head->previous;
		//temp_ptr = a_head;
		a_head = a_head->next;
		//free(temp_ptr);
		//temp_ptr = NULL;
	}
	printf("%d\n", a_head->content);
	printf("%d\n", a_head->previous->content);
	printf("%d\n", a_head->next->content);
	printf("oui\n");
}
