/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:35:38 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/30 00:17:31 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	node	*a_head;
	node	*b_head;
	char			**list;

	if (!(list = check_errors(&argc, argv, NULL)))
		exit(EXIT_SUCCESS);
	if (!(a_head = create_list(argc, list)))
	{
		ft_free(list);
		exit(EXIT_SUCCESS);
	}
	ft_free(list);
	b_head = NULL;
	set_final(a_head);
	set_group(a_head);
	if (is_sorted(a_head))
	{
		clean(a_head);
		exit(EXIT_SUCCESS);
	}
	if (argc == 5)
		sort_five(&a_head, &b_head);
	else
	{
		sort(&a_head, &b_head);
		sort_three(a_head);
		sort_back(&a_head, &b_head);
	}
	allo_a(a_head);
	allo_b(b_head);
	clean(a_head);
	//printf("CLEAN A FAIT\n");
	clean(b_head);
	//printf("CLEAN B FAIT\n");
	return (0);
}

node	*create_list(int argc, char **argv)
{
	node	*head;
	node	*new_element;
	node	*previous_element;
	int				i;

	i = 0;
	if (!make_malloc(head = malloc(sizeof(node))))
		return (NULL);
	//head = malloc(sizeof(node));
	//if (!head)
	//	return (NULL);
	head->content = ft_atoi(argv[i], NULL);
	head->index = i + 1;
	head->final = 1;
	new_element = head;
	while (argc > ++i)
	{
		if (!make_malloc(new_element->next = malloc(sizeof(node))))
		{
			clean(head);
			return (NULL);
		}
		previous_element = new_element;
		new_element = new_element->next;
		new_element->content = ft_atoi(argv[i], NULL);
		new_element->index = i + 1;
		new_element->final = 1;
		new_element->previous = previous_element;
	}
	new_element->next = head;
	head->previous = new_element;
	return (head);
}

void	set_final(node *head)
{
	node	*temp_1;
	node	*temp_2;

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

void	set_group(node *head)
{
	node	*temp;
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
		{
			//if ((temp->final / (list_size(head) / 10)) < k)
			if (temp->final < ((list_size(head) / 17) + 1) * k)
				temp->group = k;
			else
				k++;
		}
		temp = temp->next;
	}
}

void	clean(node *head)
{
	node	*temp_first;
	node	*temp_second;

	if (!head)
		return ;
	temp_first = head;
	temp_second = temp_first->next;
	while (temp_second != head)
	{
		free(temp_first);
		temp_first = temp_second;
		if (!temp_second)
			break;
		temp_second = temp_second->next;
	}
	free(temp_first);
	temp_first = NULL;
	temp_second = NULL;
	head = NULL;
}

void	allo_a(node *head)
{
	node	*temp;
	int				i;
	int				j;

	if (!head)
	{
		printf("-- LA PILE A EST VIDE --\n");
		return ;
	}
	temp = head;
	i = temp->content;
	//printf("i = %d\n", i);
	j = i + 1;
	printf("      -- PILE A --\n");
	while (j != i)
	{
		printf("%d / index = %d / final = %d / groupe = %d\n", temp->content, temp->index, temp->final, temp->group);
		temp = temp->next;
		j = temp->content;
		//printf("j = %d\n", j);
	}
}

void	allo_b(node *head)
{
	node	*temp;
	int				i;
	int				j;

	if (!head)
	{
		printf("-- LA PILE B EST VIDE --\n");
		return ;
	}
	temp = head;
	i = temp->content;
	j = i + 1;
	printf("      -- PILE B --\n");
	while (j != i)
	{
		printf("%d / index = %d / final = %d / groupe = %d\n", temp->content, temp->index, temp->final, temp->group);
		temp = temp->next;
		j = temp->content;
	}
}

void	*make_malloc(void *ptr)
{
	if (!ptr)
		return (NULL);
	return (ptr);
}
