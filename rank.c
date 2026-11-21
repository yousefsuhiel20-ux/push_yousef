/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuhuss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 21:38:30 by yabuhuss          #+#    #+#             */
/*   Updated: 2026/11/21 00:11:00 by yabuhuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rank_fun(t_list *stack)
{
	t_list	*start1;
	t_list	*other;
	int		rank;

	start1 = stack;
	while (start1)
	{
		rank = 0;
		other = stack;
		while (other)
		{
			if (other->content < start1->content)
				rank++;
			other = other->next;
		}
		start1->index = rank;
		start1 = start1->next;
	}
	return (0);
}
