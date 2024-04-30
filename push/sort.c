/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:43:21 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/30 21:45:35 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_list_element **a_head, t_list_element **b_head)
{
	int				nth_group;
	t_list_element	*ptr;
	int				i;
	//int				size;

	nth_group = 2;
	//size = list_size(*a_head);
	while (*a_head)
	{
		//printf("OUI 1\n");
		i = 0;
		ptr = *a_head;
		//printf("taille 1 : %d\n", list_size(*a_head));
		while (i < list_size(*a_head))
		{
			//printf("taille : %d\n", list_size(*a_head));
			//ptr = *a_head;
			if (ptr->group == nth_group)
			{
				printf("PTR GROUPPPPPP : %d\n", ptr->group);
				printf("NTH GROUP : %d\n", nth_group);
				while (*a_head != ptr)
				{
					if (ptr->index < list_size(*a_head) / 2)
					{
						rotate_a(*a_head);
					}
					else
					{
						reverse_rotate_a(*a_head);
					}
				}
				printf("OUI 1 : %d\n", (*a_head)->group);
				push_b(a_head, b_head);
				ptr = *a_head;
				printf("OUI 2 : %d\n", (*a_head)->group);
				printf("taille 2 : %d\n", list_size(*a_head));
				printf("PTR GROUP : %d\n", ptr->group);
				printf("NTH GROUP XXX : %d\n", nth_group);
				printf("IIIII : %d\n", i);
			}
			else
			{
				printf("else ??\n");
				ptr = ptr->next;
			}
			i++;
		}
		nth_group++;
		printf("NTH GROUP AAA : %d\n", nth_group);
	}
}









	
/* 	int	i;
	int	size;
	t_list_element	*temp_ptr;
	//int	j;

	i = 0;
	size = list_size(*a_head);
	//temp_ptr = *a_head;
	//j = 1;
	while (i++ < size / 2)
		push_b(a_head, b_head);
	while (*a_head)
	{
		while ((*a_head) != find_min(*a_head))
		{
			if (find_min(*a_head)->index < list_size(*a_head) / 2)
				rotate_a(*a_head);
			else
				reverse_rotate_a(*a_head);
		}
		//(*a_head)->final = j;
		//j++;
		push_b(a_head, b_head);
	}
	while (i++ < size)
		push_a(a_head, b_head);
	while (*b_head)
	{
		while ((*b_head) != find_min(*b_head))
		{
			if (find_min(*b_head)->index < list_size(*b_head) / 2)
				rotate_b(*b_head);
			else
				reverse_rotate_b(*b_head);
		}
		temp_ptr = (*b_head)->next;
		while (temp_ptr != *b_head)
		{
			if ((*b_head)->final == temp_ptr->final - 1)
				push_a(a_head, b_head);
			temp_ptr = temp_ptr->next;
		}
		temp_ptr = (*b_head)->next;
		while ((*b_head)->final != (*a_head)->final + 1 && temp_ptr != *b_head)
		{
			rotate_a(*a_head);
			temp_ptr = temp_ptr->next;
		}
		push_a(a_head, b_head);
	} */
	/* while (*a_head)
	{
		push_b(a_head, b_head);
		if ((*b_head)->content < (*b_head)->next->content)
			swap_b(*b_head);
	} */
	//while (*b_head)
	//	push_a(a_head, b_head);
