/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:16:00 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/12 16:17:21 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_b(t_list_element *head)
{
	int				temp_int;
	t_list_element	*temp_ptr;

	if (head->next == head || !head)
		return ;
	temp_ptr = head->next;
	temp_int = temp_ptr->content;
	temp_ptr->content = head->content;
	head->content = temp_int;
	//free(temp_ptr);
	temp_ptr = NULL;
	write(1, "sb\n", 3);
}
