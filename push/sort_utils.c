/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:28:25 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/07 19:53:57 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	list_size(t_list_element *head)
{
	t_list_element	*temp_ptr;
	int				i;

	temp_ptr = head;
	i = 1;
	if(!head)
		return (0);
	while (temp_ptr->next != head)
	{
		i++;
		temp_ptr = temp_ptr->next;
	}
	return (i);
}

t_list_element	*find_min(t_list_element *head)
{
	t_list_element	*temp;
	int				i;

	temp = head->next;
	i = head->content;
	while (temp != head)
	{
		if (temp->content < i)
			i = temp->content;
		temp = temp->next;
	}
	while (temp->content != i)
		temp = temp->next;
	return (temp);
}

int	is_sorted(t_list_element *head)
{
	t_list_element	*temp_1;
	t_list_element	*temp_2;
	int				first_content;

	first_content = head->content;
	temp_1 = head->next;
	temp_2 = temp_1->next;
	if (head->content > temp_1->content)
		return (0);
	while (temp_2->content != first_content)
	{
		if (temp_1->content > temp_2->content)
			return (0);
		temp_1 = temp_1->next;
		temp_2 = temp_2->next;
	}
	return (1);
}
