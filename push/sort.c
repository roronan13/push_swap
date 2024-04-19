/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:43:21 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/19 02:09:22 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_list_element **a_head, t_list_element **b_head)
{
	//int	i;
	//t_list_element	*temp_ptr;
	//int	j;

	//i = 1;
	//temp_ptr = *a_head;
	//j = 1;
	/* while (i < size / 2)
	{
		push_b(a_head, b_head);
		i++;
	} */
	while (*a_head)
	{
		while ((*a_head) != find_min(*a_head))
		{
			rotate_a(*a_head);
		}
		//(*a_head)->final = j;
		//j++;
		push_b(a_head, b_head);
	}
	//allo_b(*b_head);
	while (*b_head)
		push_a(a_head, b_head);
}
