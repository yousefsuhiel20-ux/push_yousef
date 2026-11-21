/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuhuss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 21:38:25 by yabuhuss          #+#    #+#             */
/*   Updated: 2026/11/21 00:25:57 by yabuhuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_val(t_data *head)
{
	int	one;
	int	tow;

	if (!head || !head->stack_a || !head->stack_a->next)
		return ;
	one = head->stack_a->index;
	tow = head->stack_a->next->index;
	if (one > tow)
		sa(head);
}

void	three_val(t_data *head)
{
	int	one;
	int	two;
	int	three;

	if (!head || !head->stack_a || !head->stack_a->next
		|| !head->stack_a->next->next)
		return ;
	one = head->stack_a->index;
	two = head->stack_a->next->index;
	three = head->stack_a->next->next->index;
	if (one < two && two > three && one < three)
		(sa(head), ra(head));
	else if (one > two && two < three && one < three)
		sa(head);
	else if (one < two && two > three && one > three)
		rra(head);
	else if (one > two && two < three && one > three)
		ra(head);
	else if (one > two && two > three)
		(sa(head), rra(head));
}

void	five_val(t_data *head)
{
	if (!head || !head->stack_a || !head->stack_a->next
		|| !head->stack_a->next->next || !head->stack_a->next->next->next
		|| !head->stack_a->next->next->next->next)
		return ;
	rank_fun(head->stack_a);
	while (head->stack_a->index != 0)
		ra(head);
	pb(head);
	while (head->stack_a->index != 1)
		ra(head);
	pb(head);
	three_val(head);
	pa(head);
	pa(head);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_data	data;
// 	t_list	*tmp;
// 	int		vals[5] = {4, 2, 0, 3, 1};
// 	int		i;

// 	data.stack_a = NULL;
// 	data.stack_b = NULL;
// 	i = 5;
// 	while (--i >= 0)
// 	{
// 		tmp = malloc(sizeof(t_list));
// 		if (!tmp)
// 			return (1);
// 		tmp->content = vals[i];
// 		tmp->index = 0;
// 		tmp->next = data.stack_a;
// 		data.stack_a = tmp;
// 	}
// 	five_val(&data);
// 	tmp = data.stack_a;
// 	while (tmp)
// 	{
// 		printf("content: %d | index: %d\n", tmp->content, tmp->index);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }