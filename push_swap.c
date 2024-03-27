/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:35:38 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/27 17:42:07 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list_element	*nbr_list;

	check_errors(argc, argv);
	nbr_list = create_list(argc, argv);
	//allo(nbr_list);
	swap_a(nbr_list);
	allo(nbr_list);
	clean(nbr_list);
	//free(nbr_list);
	//nbr_list = NULL;
	return (0);
}

t_list_element	*create_list(int argc, char **argv)
{
	t_list_element	*head;
	t_list_element	*new_element;
	t_list_element	*previous_element;
	
	head = malloc(sizeof(t_list_element));
	//printf("taille: %ld\n",sizeof(t_list_element));
	if (!head)
		return (NULL);
	*argv++;
	//printf("%s\n", *argv);
	head->content = ft_atoi(*argv);
	head->next = NULL;
	head->previous = NULL;
	new_element = head;
	//printf("coucou\n%p", head);
	*argv++;
	while (*argv && argc)
	{
		new_element->next = malloc(sizeof(t_list_element));
		//printf("taille: %ld\n",sizeof(t_list_element));
		if (!new_element->next)
			return (NULL);
		previous_element = new_element;
		// question below
		new_element = new_element->next;
		new_element->content = ft_atoi(*argv);
		new_element->next = NULL;
		new_element->previous = previous_element;
		*argv++;
	}
	new_element->next = head;
	head->previous = new_element;
	//free(new_element);
	//new_element = NULL;
	//free(previous_element);
	//previous_element = NULL;
	return (head);
}

void	clean(t_list_element *head)
{
	/* t_list_element	*temp;
	int	a;
	int	b;

	temp = head->next;
	a = head->content;
	b = temp->content;
	while (a != b)
	{
		free(head);
		head = temp;
		temp = temp->next;
		b = temp->content;
	}
	free(head);
	head = NULL;
	temp = NULL; */
	t_list_element	*temp_first;
	t_list_element	*temp_second;

	temp_first = head;
	temp_second = temp_first->next;
	while (temp_second != head)
	{
		free(temp_first);
		temp_first = temp_second;
		temp_second = temp_second->next;
	}
	free(temp_first);
	temp_first = NULL;
	temp_second = NULL;
	head = NULL;
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
		temp = temp->next;
		j = temp->content;
	}
	//free(temp);
	//temp = NULL;
}
