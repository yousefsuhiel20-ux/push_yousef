/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_medium_fun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuhuss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 19:32:56 by yabuhuss          #+#    #+#             */
/*   Updated: 2026/11/26 19:45:10 by yabuhuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack(t_list *head)
{
	int	len;

	len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (head);
}

int	find_max_pos(t_list *head)
{
	int	max_index;
	int	max_pos;
	int	pos;

	max_index = head->index;
	max_pos = 0;
	pos = 0;
	while (head)
	{
		if (head->index > max_index)
		{
			max_index = head->index;
			max_pos = pos;
		}
		head = head->next;
		pos++;
	}
	return (max_pos);
}

void	rotate_b(t_data *head, int pos, int len)
{
	int	moves;

	if (pos <= len / 2)
	{
		while (pos > 0)
		{
			rb(head);
			pos--;
		}
	}
	else
	{
		moves = len - pos;
		while (moves > 0)
		{
			rrb(head);
			moves--;
		}
	}
}
