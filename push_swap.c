/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:35:38 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/20 19:17:33 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list_element	*nbr_list;

	nbr_list = NULL;
	check_errors(argc, argv);
	nbr_list = create_list(argc, argv);
	allo(nbr_list);
	return (0);
}

t_list_element	*create_list(int argc, char **argv)
{
	t_list_element	*head;
	t_list_element	*new_element;
	int	i;
	
i = 1;
	head = malloc(sizeof(t_list_element));
	if (!head)
		return (NULL);
	head->content = ft_atoi(argv[i]);
	head->next = NULL;
	head->previous = NULL;
	new_element = head;
	while (argc > ++i)
	{
		new_element->next = malloc(sizeof(t_list_element));
		if (!new_element->next)
			return (NULL);
		new_element = new_element->next;
		new_element->content = ft_atoi(argv[i]);
		new_element->next = NULL;
	}
	//new_element->next = head;
	return (head);
}

void	allo(t_list_element *head)
{
	t_list_element *temp;
	int	i = 0;

	temp = head;
	while (temp)
	{
		printf("%d\n", temp->content);
		temp = temp->next;
		i++;
	}
}
