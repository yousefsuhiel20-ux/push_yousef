/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuhuss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 23:04:57 by yabuhuss          #+#    #+#             */
/*   Updated: 2026/11/25 23:18:17 by yabuhuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_fun(t_data *head, int size)
{
	double	disorder;

	if (!head || !head->stack_a || size <= 1)
		return ;
	disorder = disorder_fun(size, head);
	if (disorder < 0.2)
		simple_sort(head, size);
	else if (disorder < 0.5)
		medium_sort(head, size);
	else
		complex_sort(head, size);
}
