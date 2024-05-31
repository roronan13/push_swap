/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:35:38 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/31 20:11:54 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node			*a_head;
	t_node			*b_head;
	char			**list;

	list = check_errors(&argc, argv, NULL);
	if (list)
	{
		a_head = create(argc, list);
		if (a_head)
		{
			ft_free(list);
			b_head = NULL;
			set_group((set_final(a_head), a_head));
			if (is_sorted(a_head))
				exit((clean(a_head), EXIT_SUCCESS));
			if (argc == 5)
				sort_five(&a_head, &b_head);
			else
				sort_back((sort(&a_head, &b_head), sort_three(a_head), \
				&a_head), &b_head);
			return (clean(a_head), clean(b_head), 0);
		}
		exit((ft_free(list), EXIT_FAILURE));
	}
	exit(EXIT_FAILURE);
}

void	create_list_2(t_node *prev_elem, t_node **new_elem, char **list, int i)
{
	prev_elem = *new_elem;
	*new_elem = (*new_elem)->next;
	(*new_elem)->content = ft_atoi(list[i], NULL);
	(*new_elem)->index = i + 1;
	(*new_elem)->final = 1;
	(*new_elem)->previous = prev_elem;
}

t_node	*create(int size, char **list)
{
	t_node	*head;
	t_node	*new_element;
	t_node	*previous_element;
	int				i;

	i = 0;
	previous_element = NULL;
	head = malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->content = ft_atoi(list[i], NULL);
	head->index = i + 1;
	head->final = 1;
	new_element = head;
	while (size > ++i)
	{
		new_element->next = malloc(sizeof(t_node));
		if (!new_element->next)
			return (clean(head), NULL);
		create_2(previous_element, &new_element, list, i);
	}
	new_element->next = head;
	head->previous = new_element;
	return (head);
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

void	clean(t_node *head)
{
	t_node	*temp_first;
	t_node	*temp_second;

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
