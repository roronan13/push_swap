/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:43:21 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/04 17:19:14 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_five(t_node **a_head, t_node **b_head)
{
	while (list_size(*a_head) > 3)
	{
		while ((*a_head)->final != 1 && (*a_head)->final != 2)
			rotate_a(*a_head);
		push_b(a_head, b_head);
	}
	sort_three(*a_head);
	push_a(a_head, b_head);
	push_a(a_head, b_head);
	if ((*a_head)->content > (*a_head)->next->content)
		swap_a(*a_head);
}

void	sort(t_node **a_head, t_node **b_head)
{
	int				nth_group;
	int				size;

	nth_group = 1;
	size = list_size(*a_head);
	while (list_size(*a_head) > 3)
	{
		s_1(&a_head, &b_head, size, nth_group);
		nth_group = nth_group + 2;
	}
}

void	s_1(t_node ***a_head, t_node ***b_head, int size, int nth_group)
{
	int		i;
	t_node	*ptr;
	int		current;

	i = -1;
	ptr = **a_head;
	while ((++i <= list_size(**a_head)) && list_size(**a_head) > 3)
	{
		if ((ptr->group == nth_group || ptr->group == nth_group + 1)
			&& ptr->final <= size - 3)
		{
			sort_2(&current, &ptr, &a_head);
			if ((**a_head)->final <= size - 3)
			{
				if ((**a_head)->group == nth_group)
					s_4(&i, a_head, b_head, &ptr);
				else if ((**a_head)->group == nth_group + 1)
					s_5(&i, a_head, b_head, &ptr);
			}
			else
				sort_6(&ptr, &i);
		}
		else
			ptr = ptr->next;
	}
}

void	sort_three(t_node *a_head)
{
	if (a_head == find_min(a_head))
	{
		if (a_head->next->content > a_head->previous->content)
			swap_a((reverse_rotate_a(a_head), a_head));
	}
	else if (a_head->next == find_min(a_head))
	{
		if (a_head->content < a_head->previous->content)
			swap_a(a_head);
		else
			rotate_a(a_head);
	}
	else
	{
		if (a_head->content < a_head->next->content)
			reverse_rotate_a(a_head);
		else
			reverse_rotate_a((swap_a(a_head), a_head));
	}
}

void	sort_back(t_node **a_head, t_node **b_head)
{
	int		max;
	t_node	*ptr;

	while (*b_head)
	{
		ptr = *b_head;
		max = list_size(*b_head);
		while (ptr->final != max)
			ptr = ptr->next;
		while ((*b_head)->final != max)
		{
			if ((*b_head)->final == max - 1)
				push_a(a_head, b_head);
			else if (ptr->index <= (list_size(*b_head) / 2) + 1)
				rotate_b(*b_head);
			else
				reverse_rotate_b(*b_head);
		}
		push_a(a_head, b_head);
		if ((*a_head)->next && (*a_head)->content > (*a_head)->next->content)
			swap_a(*a_head);
	}
}
