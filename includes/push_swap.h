/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:24:29 by rpothier          #+#    #+#             */
/*   Updated: 2024/06/04 17:56:14 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct list
{
	int			content;
	int			index;
	int			final;
	int			group;
	struct list	*next;
	struct list	*previous;
}	t_node;

t_node			*create(int size, char **list);
void			crea_2(t_node *prev_ele, t_node **new_ele, char **list, int i);
void			clean(t_node *head);

void			set_group(t_node *head);
void			set_group_2(t_node *head, t_node **temp, int *k);
void			set_final(t_node *head);

char			**check_errors(int *argc, char **argv, char **list);
void			check_params(int argc, char **argv);
int				check_number(int size, char **list);
void			check_long(int size, char **list);
int				check_twice(int size, char **list);

int				check_err_one_arg(char **first_list, char **argv, char ***list);
int				check_errors_more_args(char ***list, char **argv, int *argc);

int				ft_atoi(char *list, char **ptr_list);
void			check_overflow(char *list, int i, int resu, char **ptr_list);
int				*fill_int_table(int size, char **list);
int				tab_size(char **tab);

void			sort_five(t_node **a_head, t_node **b_head);
void			sort(t_node **a_head, t_node **b_head);
void			s_1(t_node ***a_head, t_node ***b_head, int size, int nth_gr);
void			sort_three(t_node *a_head);
void			sort_back(t_node **a_head, t_node **b_head);

void			sort_2(int *current, t_node **ptr, t_node ****a_head);
void			sort_3(t_node **ptr, t_node ***a_head);
void			s_4(int *i, t_node ***a_head, t_node ***b_head, t_node **ptr);
void			s_5(int *i, t_node ***a_head, t_node ***b_head, t_node **ptr);
void			sort_6(t_node **ptr, int *i);

int				list_size(t_node *head);
t_node			*find_min(t_node *head);
int				is_sorted(t_node *head);

size_t			ft_count(char const *s, char c);
char			*ft_fill(const char *s, char c, size_t j);
char			**ft_free(char **ptr);
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, char const *set);

size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strdup(const char *s);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

void			swap_a(t_node *head);

void			swap_b(t_node *head);

void			swap_a_swap_b(t_node *a_head, t_node *b_head);
void			swap(t_node *head);

void			push_a(t_node **a_head, t_node **b_head);
void			new_a_list(t_node **a_head, t_node **b_head);
void			add_to_a_list(t_node **a_head, t_node **b_head, t_node **ptr);

void			push_b(t_node **a_head, t_node **b_head);
void			new_b_list(t_node **a_head, t_node **b_head);
void			add_to_b_list(t_node **a_head, t_node **b_head, t_node **ptr);

void			rotate_a(t_node *head);

void			rotate_b(t_node *head);

void			rotate_a_rotate_b(t_node *a_head, t_node *b_head);
void			rotate(t_node *head);
void			rotate_group(t_node *head);

void			reverse_rotate_a(t_node *head);

void			reverse_rotate_b(t_node *head);

void			rev_rot_a_rev_rot_b(t_node *a_head, t_node *b_head);
void			reverse_rotate(t_node *head);
void			reverse_rotate_group(t_node *head);

t_node			*ft_lst_last(t_node *head);

#endif