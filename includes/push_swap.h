/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:24:29 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/05 00:21:15 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct list
{
	int			content;
	struct list	*next;
	struct list	*previous;
}	t_list_element;

void			check_errors(int argc, char **argv);
void			check_params(int argc, char **argv);
void			check_number(int argc, char **argv);
void			check_long(int argc, char **argv);
void			check_twice(int argc, char **argv);
int				ft_atoi(char *argv);
void			check_overflow(char *argv, int i, int resu);
int				*fill_int_table(int argc, char **argv);
t_list_element	*create_list(int argc, char **argv);
void			allo(t_list_element *head);
void			swap_a(t_list_element *head);
void			rotate_a(t_list_element *head);
void			reverse_rotate_a(t_list_element *head);
void			clean(t_list_element *head);
void			make_malloc(void *ptr);

#endif