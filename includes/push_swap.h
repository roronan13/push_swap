/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:24:29 by rpothier          #+#    #+#             */
/*   Updated: 2024/05/29 17:17:48 by rpothier         ###   ########.fr       */
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
}	node;

char			**check_errors(int *argc, char **argv, char **list);
void			check_params(int argc, char **argv);
void			check_number(int argc, char **argv);
void			check_long(int argc, char **argv);
int				check_twice(int argc, char **argv);


int				ft_atoi(char *argv);
void			check_overflow(char *argv, int i, int resu);
int				*fill_int_table(int argc, char **argv);


node	*create_list(int argc, char **argv);
void			set_final(node *head);
void			set_group(node *head);
void			clean(node *head);
void			*make_malloc(void *ptr);
void			allo_a(node *head);
void			allo_b(node *head);


void			sort(node **a_head, node **b_head);
void			sort_back(node **a_head, node **b_head);
void			sort_three(node *a_head);
void	sort_five(node **a_head, node **b_head);


int				list_size(node *head);
node	*find_min(node *head);
int				is_sorted(node *head);

char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
int	tab_size(char **tab);
char	*ft_strdup(const char *s);
char	**ft_free(char **ptr);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);


void			swap_a(node *head);
void			swap_b(node *head);
void			swap_a_swap_b(node *a_head, node *b_head);
void			swap(node *head);
void			push_a(node **a_head, node **b_head);
void			new_a_list(node **a_head, node **b_head);
void			add_to_a_list(node **a_head, node **b_head, node **temp_ptr);
void			push_b(node **a_head, node **b_head);
void			new_b_list(node **a_head, node **b_head);
void			add_to_b_list(node **a_head, node **b_head, node **temp_ptr);
void			rotate_a(node *head);
void			rotate_b(node *head);
void			rotate_a_rotate_b(node *a_head, node *b_head);
void			rotate(node *head);
void			rotate_group(node *head);
void			reverse_rotate_a(node *head);
void			reverse_rotate_b(node *head);
void			rev_rot_a_rev_rot_b(node *a_head, node *b_head);
void			reverse_rotate(node *head);
void			reverse_rotate_group(node *head);


node	*ft_lst_last(node *head);

#endif