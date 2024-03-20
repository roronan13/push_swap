/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:35:38 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/21 00:35:59 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list_element	*nbr_list;

	check_errors(argc, argv);
	nbr_list = create_list(argc, argv);
	allo(nbr_list);
	return (0);
}

t_list_element	*create_list(int argc, char **argv)
{
	t_list_element	*head;
	t_list_element	*new_element;
	t_list_element	*previous_element;
	
	head = malloc(sizeof(t_list_element));
	if (!head)
		return (NULL);
	*argv++;
	//printf("%s\n", *argv);
	head->content = ft_atoi(*argv);
	head->next = NULL;
	head->previous = NULL;
	new_element = head;
	*argv++;
	while (*argv && argc)
	{
		new_element->next = malloc(sizeof(t_list_element));
		if (!new_element->next)
			return (NULL);
		previous_element = new_element;
		new_element = new_element->next;
		new_element->content = ft_atoi(*argv);
		new_element->next = NULL;
		new_element->previous = previous_element;
		*argv++;
	}
	new_element->next = head;
	head->previous = new_element;
	return (head);
}

void	allo(t_list_element *head)
{
	t_list_element *temp;
	int	i;
	int	j;

	temp = head;
	i = temp->content;
	j = i + 1;
	while (j != i)
	{
		printf("%d\n", temp->content);
		temp = temp->previous;
		j = temp->content;
	}
}
