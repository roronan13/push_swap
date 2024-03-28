/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:35:38 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/28 22:02:06 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list_element	*nbr_list;

	check_errors(argc, argv);
	nbr_list = create_list(argc, argv);
	swap_a(nbr_list);
	allo(nbr_list);
	clean(nbr_list);
	return (0);
}

t_list_element	*create_list(int argc, char **argv)
{
	t_list_element	*head;
	t_list_element	*new_element;
	t_list_element	*previous_element;
	int				i;

	i = 1;
	make_malloc(head = malloc(sizeof(t_list_element)));
	head->content = ft_atoi(argv[i]);
	head->next = NULL;
	head->previous = NULL;
	new_element = head;
	while (argc > ++i)
	{
		make_malloc(new_element->next = malloc(sizeof(t_list_element)));
		previous_element = new_element;
		new_element = new_element->next;
		new_element->content = ft_atoi(argv[i]);
		new_element->next = NULL;
		new_element->previous = previous_element;
	}
	new_element->next = head;
	head->previous = new_element;
	return (head);
}

void	clean(t_list_element *head)
{
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
	t_list_element	*temp;
	int				i;
	int				j;

	temp = head;
	i = temp->content;
	j = i + 1;
	while (j != i)
	{
		printf("%d\n", temp->content);
		temp = temp->next;
		j = temp->content;
	}
}

void	make_malloc(void *ptr)
{
	if (!ptr)
		exit(EXIT_FAILURE);
}
