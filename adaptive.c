/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuhuss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 23:04:57 by yabuhuss          #+#    #+#             */
/*   Updated: 2026/11/26 20:33:09 by yabuhuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_fun(t_data *head, int size)
{
	double	disorder;

	if (!head || !head->stack_a || size <= 1)
		return ;
	disorder = disorder_fun(size, head);
	head->disorder = disorder;
	if (disorder < 0.2)
	{
		head->strat_name = "Adaptive";
		head->strat_class = "O(n^2)";
		simple_sort(head, size);
	}
	else if (disorder < 0.5)
	{
		head->strat_name = "Adaptive";
		head->strat_class = "O(n*sqrt(n))";
		medium_sort(head, size);
	}
	else
	{
		head->strat_name = "Adaptive";
		head->strat_class = "O(n log n)";
		complex_sort(head, size);
	}
}
