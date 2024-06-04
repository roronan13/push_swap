/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:35:38 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/04 16:48:10 by rpothier         ###   ########.fr       */
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
		crea_2(previous_element, &new_element, list, i);
	}
	new_element->next = head;
	head->previous = new_element;
	return (head);
}

void	crea_2(t_node *prev_ele, t_node **new_ele, char **list, int i)
{
	prev_ele = *new_ele;
	*new_ele = (*new_ele)->next;
	(*new_ele)->content = ft_atoi(list[i], NULL);
	(*new_ele)->index = i + 1;
	(*new_ele)->final = 1;
	(*new_ele)->previous = prev_ele;
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
			break ;
		temp_second = temp_second->next;
	}
	free(temp_first);
	temp_first = NULL;
	temp_second = NULL;
	head = NULL;
}
