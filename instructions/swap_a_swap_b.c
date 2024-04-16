/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_swap_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpothier <rpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:32:12 by rpothier          #+#    #+#             */
/*   Updated: 2024/04/16 16:19:28 by rpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a_swap_b(t_list_element *a_head, t_list_element *b_head)
{
	swap_a(a_head);
	swap_b(b_head);
	write(1, "ss\n", 3);
}
