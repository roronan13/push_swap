/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:35:38 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/20 21:36:18 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list_element	*nbr_list;

	check_errors(argc, argv);
	nbr_list = create_list(argc, argv);
	return (0);
}

t_list_element	*create_list(int argc, char **argv)
{
	t_list_element	*head;
	t_list_element	*new_element;
	
	head = malloc(sizeof(t_list_element));
	if (!head)
		return (NULL);
	*argv++;
	head->content = ft_atoi(*argv);
	head->next = NULL;
	head->previous = NULL;
	new_element = head;
	while (*argv && argc)
	{
		new_element->next = malloc(sizeof(t_list_element));
		if (!new_element->next)
			return (NULL);
		new_element = new_element->next;
		new_element->content = ft_atoi(*argv);
		new_element->next = NULL;
		*argv++;
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
