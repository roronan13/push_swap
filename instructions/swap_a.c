/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:43:27 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/27 15:39:18 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_list_element *head)
{
	int	temp_int;
	t_list_element	*temp_ptr;
	
	if (head->next == head || !head)
		return ;
	temp_ptr = head;
	temp_ptr = temp_ptr->next;
	temp_int = temp_ptr->content;
	temp_ptr->content = head->content;
	head->content = temp_int;
	//free(temp_ptr);
	//temp_ptr = NULL;
	write(1, "sa\n", 3);
}
