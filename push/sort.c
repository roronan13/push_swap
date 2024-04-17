/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:43:21 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/17 20:34:05 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_list_element **a_head, t_list_element **b_head)
{
	//int	size;
	//int	i;
	t_list_element	*temp_ptr;

	//size = list_size(*a_head);
	//i = 0;
	temp_ptr = *a_head;
	/* while (i < size / 2)
	{
		push_b(a_head, b_head);
		i++;
	} */
	while (temp_ptr->next != *a_head)
	{
		
		if (temp_ptr->content < temp_ptr->next->content)
		{
			swap_a(*a_head);
			push_b(a_head, b_head);
			temp_ptr = *a_head;
		}
		else
		{
			temp_ptr = temp_ptr->next;
		}
	}
}
