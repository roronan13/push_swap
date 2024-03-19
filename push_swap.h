/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:24:29 by rpothier          #+#    #+#             */
/*   Updated: 2024/03/19 19:33:24 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct list
{
	int			nbr;
	struct list	*next;
	struct list	*previous;
} list;


void	check_errors(int argc, char **argv);
void	check_params(int argc, char **argv);
void	check_number(int argc, char **argv);
void	check_long(int argc, char **argv);
void	check_twice(int argc, char **argv);
int		ft_atoi(char *argv);
void	check_overflow(char *argv, int i, int resu);
int		*fill_int_table(int argc, char **argv);

#endif