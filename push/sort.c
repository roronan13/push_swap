/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:43:21 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/31 18:52:25 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_node **a_head, t_node **b_head)
{
	int				nth_group;
	//t_node			*ptr;
	//int				i;
	int				size;
	//int				current;

	nth_group = 1;
	size = list_size(*a_head);
	while (list_size(*a_head) > 3)
	{
		sort_1(&a_head, &b_head, size, nth_group);
		/* i = -1;
		ptr = *a_head;
		while ((++i <= list_size(*a_head)) && list_size(*a_head) > 3)
		{
			if ((ptr->group == nth_group || ptr->group == nth_group + 1) 
				&& ptr->final <= size - 3)
			{
				current = ptr->content;
				while ((*a_head)->content != current)
					sort_2(&ptr, &a_head);
				if ((*a_head)->final <= size - 3)
				{
					if ((*a_head)->group == nth_group)
						sort_3(&i, &a_head, &b_head, &ptr);
					else if ((*a_head)->group == nth_group + 1)
						sort_4(&i, &a_head, &b_head, &ptr);
				}
				else
					sort_5(&ptr, &i);
			}
			else
				ptr = ptr->next;
		}
		nth_group = nth_group + 2; */
		nth_group = nth_group + 2;
	}
}

void	sort_1(t_node ***a_head, t_node ***b_head, int size, int nth_group)
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
					sort_4(&i, a_head, b_head, &ptr);
				else if ((**a_head)->group == nth_group + 1)
					sort_5(&i, a_head, b_head, &ptr);
			}
			else
				sort_6(&ptr, &i);
		}
		else
			ptr = ptr->next;
	}
}

void	sort_3(t_node **ptr, t_node ***a_head)
{
	if ((*ptr)->index <= (list_size(**a_head) / 2) + 1)
		rotate_a(**a_head);
	else
		reverse_rotate_a(**a_head);
}

void	sort_4(int *i, t_node ***a_head, t_node ***b_head, t_node **ptr)
{
	push_b((*i = -1, *a_head), *b_head);
	*ptr = **a_head;
}

void	sort_5(int *i, t_node ***a_head, t_node ***b_head, t_node **ptr)
{
	push_b((*i = -1, *a_head), *b_head);
	rotate_b(**b_head);
	*ptr = **a_head;
}

void	sort_6(t_node **ptr, int *i)
{
	*ptr = (*ptr)->next;
	*i = -1;
}

void	sort_2(int *current, t_node **ptr, t_node ****a_head)
{
	*current = (*ptr)->content;
	while ((***a_head)->content != *current)
		sort_3(ptr, *a_head);
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
