/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuhuss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:55:44 by yabuhuss          #+#    #+#             */
/*   Updated: 2026/11/26 20:13:36 by yabuhuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	node_val(t_list *node)
{
	return (node->content);
}

double	disorder_fun(long n, t_data *head)
{
	t_list	*i;
	t_list	*j;
	double	total_pairs;
	double	mistakes;

	mistakes = 0.0;
	if (!head || !head->stack_a || n <= 1)
		return (mistakes);
	total_pairs = ((double)n * ((double)n - 1.0)) / 2.0;
	i = head->stack_a;
	while (i && i->next)
	{
		j = i->next;
		while (j)
		{
			if (node_val(i) > node_val(j))
				mistakes += 1.0;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / total_pairs);
}
