/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:07:05 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/04 17:08:51 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(int *current, t_node **ptr, t_node ****a_head)
{
	*current = (*ptr)->content;
	while ((***a_head)->content != *current)
		sort_3(ptr, *a_head);
}

void	sort_3(t_node **ptr, t_node ***a_head)
{
	if ((*ptr)->index <= (list_size(**a_head) / 2) + 1)
		rotate_a(**a_head);
	else
		reverse_rotate_a(**a_head);
}

void	s_4(int *i, t_node ***a_head, t_node ***b_head, t_node **ptr)
{
	push_b((*i = -1, *a_head), *b_head);
	*ptr = **a_head;
}

void	s_5(int *i, t_node ***a_head, t_node ***b_head, t_node **ptr)
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
