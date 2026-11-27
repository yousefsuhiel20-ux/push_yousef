/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuhuss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 21:04:47 by yabuhuss          #+#    #+#             */
/*   Updated: 2026/11/26 20:14:50 by yabuhuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_num;
	int	max_bits;

	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	sort_bit(t_data *head, int size, int bit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((head->stack_a->index >> bit) & 1) == 0)
			pb(head);
		else
			ra(head);
		i++;
	}
	while (head->stack_b)
		pa(head);
}

void	complex_sort(t_data *head, int size)
{
	int	max_bit;
	int	bit;

	if (!head || !head->stack_a)
		return ;
	size = stack_size(head->stack_a);
	if (size > 1)
		rank_fun(head->stack_a);
	max_bit = get_max_bits(size);
	bit = 0;
	while (bit < max_bit)
	{
		sort_bit(head, size, bit);
		bit++;
	}
}
