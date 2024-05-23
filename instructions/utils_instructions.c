/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:27:56 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/23 15:42:36 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

node	*ft_lst_last(node *head)
{
	node	*temp_ptr;

	temp_ptr = head;
	if(!head)
		return (NULL);
	while (temp_ptr->next != head)
		temp_ptr = temp_ptr->next;
	return (temp_ptr);
}
