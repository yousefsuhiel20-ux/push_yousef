/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuhuss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 20:46:33 by yabuhuss          #+#    #+#             */
/*   Updated: 2026/11/21 22:54:24 by yabuhuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static void	rot_up(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

static void	rot_down(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	sa(t_data *head)
{
	t_list	*first;
	t_list	*second;

	if (!head || !head->stack_a || !head->stack_a->next)
		return ;
	first = head->stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	head->stack_a = second;
	printf("sa\n");
}

void	ra(t_data *head)
{
	if (!head)
		return ;
	rot_up(&head->stack_a);
	printf("ra\n");
}

void	rra(t_data *head)
{
	if (!head)
		return ;
	rot_down(&head->stack_a);
	printf("rra\n");
}

void	pb(t_data *head)
{
	t_list	*node;

	if (!head || !head->stack_a)
		return ;
	node = head->stack_a;
	head->stack_a = node->next;
	node->next = head->stack_b;
	head->stack_b = node;
	printf("pb\n");
}

void	pa(t_data *head)
{
	t_list	*node;

	if (!head || !head->stack_b)
		return ;
	node = head->stack_b;
	head->stack_b = node->next;
	node->next = head->stack_a;
	head->stack_a = node;
	printf("pa\n");
}
