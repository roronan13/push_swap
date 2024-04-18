/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:28:25 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/18 19:43:38 by rpothier         ###   ########.fr       */
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
