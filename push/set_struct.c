/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:44:04 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/04 16:45:47 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_group(t_node *head)
{
	t_node			*temp;
	int				i;
	int				k;

	temp = head;
	i = 0;
	while (i++ < list_size(head))
	{
		temp->group = 0;
		temp = temp->next;
	}
	i = 0;
	while (i++ < list_size(head))
	{
		k = 1;
		while (temp->group == 0)
			set_group_2(head, &temp, &k);
		temp = temp->next;
	}
}

void	set_group_2(t_node *head, t_node **temp, int *k)
{
	if (list_size(head) <= 100)
	{
		if ((*temp)->final < ((list_size(head) / 7) + 1) * *k)
			(*temp)->group = *k;
		else
			(*k)++;
	}
	else
	{
		if ((*temp)->final < ((list_size(head) / 17) + 1) * *k)
			(*temp)->group = *k;
		else
			(*k)++;
	}
}

void	set_final(t_node *head)
{
	t_node	*temp_1;
	t_node	*temp_2;

	temp_1 = head;
	while (temp_1->next != head)
	{
		temp_2 = temp_1->next;
		while (temp_2 != head)
		{
			if (temp_1->content < temp_2->content)
				temp_2->final = temp_2->final + 1;
			else
				temp_1->final = temp_1->final + 1;
			temp_2 = temp_2->next;
		}
		temp_1 = temp_1->next;
	}
}
