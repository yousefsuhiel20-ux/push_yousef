/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuhuss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 18:55:45 by yabuhuss          #+#    #+#             */
/*   Updated: 2026/11/26 20:43:52 by yabuhuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b_to_a_fun(t_data *head)
{
	int	len;
	int	pos;

	if (!head)
		return ;
	while (head->stack_b)
	{
		len = len_stack(head->stack_b);
		pos = find_max_pos(head->stack_b);
		rotate_b(head, pos, len);
		pa(head);
	}
}

static void	chunk_fun(t_data *head, int size)
{
	int	i;
	int	range;

	if (!head || !head->stack_a || size <= 1)
		return ;
	i = 0;
	range = size / 5;
	if (range < 1)
		range = 1;
	rank_fun(head->stack_a);
	while (head->stack_a)
	{
		if (head->stack_a->index <= i)
			(pb(head), rb(head), i++);
		else if (head->stack_a->index <= i + range)
			(pb(head), i++);
		else
			ra(head);
	}
}

void	medium_sort(t_data *head, int size)
{
	if (!head || !head->stack_a || size <= 1)
		return ;
	chunk_fun(head, size);
	push_b_to_a_fun(head);
}
