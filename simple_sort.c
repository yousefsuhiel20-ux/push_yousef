/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuhuss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 21:49:42 by yabuhuss          #+#    #+#             */
/*   Updated: 2026/11/26 19:17:27 by yabuhuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_data *head)
{
	int		idx;
	int		min_val;
	int		min_pos;
	t_list	*counter_i;

	if (!head || !head->stack_a)
		return (-1);
	idx = 0;
	min_pos = 0;
	counter_i = head->stack_a;
	min_val = (counter_i->content);
	while (counter_i)
	{
		if (counter_i->content < min_val)
		{
			min_val =(counter_i->content);
			min_pos = idx;
		}
		counter_i = counter_i->next;
		idx++;
	}
	return (min_pos);
}

static void	rotate_stack(t_data *head, int size)
{
	int	r_moves;
	int	rr_moves;

	if (!head || !head->stack_a)
		return ;
	r_moves = find_min(head);
	if (r_moves < 0)
		return ;
	if (r_moves <= size / 2)
	{
		while (r_moves)
			(ra(head), r_moves--);
	}
	else
	{
		rr_moves = size - r_moves;
		while (rr_moves > 0)
			(rra(head), rr_moves--);
	}
	pb(head);
}

void	simple_sort(t_data *head, int size)
{
	if (!head || !head->stack_a || size <= 0)
		return ;
	while (size)
	{
		rotate_stack(head, size);
		size--;
	}
	while (head->stack_b)
		pa(head);
}
