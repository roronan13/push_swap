/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:24:29 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/10 15:27:51 by rpothier         ###   ########.fr       */
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
	int			index;
	int			final;
	int			group;
	struct list	*next;
	struct list	*previous;
}	t_list_element;

char			**check_errors(int *argc, char **argv, char **list);
void			check_params(int argc, char **argv);
void			check_number(int argc, char **argv);
void			check_long(int argc, char **argv);
void			check_twice(int argc, char **argv);


int				ft_atoi(char *argv);
void			check_overflow(char *argv, int i, int resu);
int				*fill_int_table(int argc, char **argv);


t_list_element	*create_list(int argc, char **argv);
void			set_final(t_list_element *head);
void			set_group(t_list_element *head);
void			clean(t_list_element *head);
void			make_malloc(void *ptr);
void			allo_a(t_list_element *head);
void			allo_b(t_list_element *head);


void			sort(t_list_element **a_head, t_list_element **b_head);
void			sort_back(t_list_element **a_head, t_list_element **b_head);
void			sort_three(t_list_element *a_head);


int				list_size(t_list_element *head);
t_list_element	*find_min(t_list_element *head);
int				is_sorted(t_list_element *head);

char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
int	tab_size(char **tab);
char	*ft_strdup(const char *s);
char	**ft_free(char **ptr);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);


void			swap_a(t_list_element *head);
void			swap_b(t_list_element *head);
void			swap_a_swap_b(t_list_element *a_head, t_list_element *b_head);
void			swap(t_list_element *head);
void			push_a(t_list_element **a_head, t_list_element **b_head);
void			new_a_list(t_list_element **a_head, t_list_element **b_head);
void			add_to_a_list(t_list_element **a_head, t_list_element **b_head, t_list_element **temp_ptr);
void			push_b(t_list_element **a_head, t_list_element **b_head);
void			new_b_list(t_list_element **a_head, t_list_element **b_head);
void			add_to_b_list(t_list_element **a_head, t_list_element **b_head, t_list_element **temp_ptr);
void			rotate_a(t_list_element *head);
void			rotate_b(t_list_element *head);
void			rotate_a_rotate_b(t_list_element *a_head, t_list_element *b_head);
void			rotate(t_list_element *head);
void			rotate_group(t_list_element *head);
void			reverse_rotate_a(t_list_element *head);
void			reverse_rotate_b(t_list_element *head);
void			rev_rot_a_rev_rot_b(t_list_element *a_head, t_list_element *b_head);
void			reverse_rotate(t_list_element *head);
void			reverse_rotate_group(t_list_element *head);


t_list_element	*ft_lst_last(t_list_element *head);

#endif