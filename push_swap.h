/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuhuss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 21:36:53 by yabuhuss          #+#    #+#             */
/*   Updated: 2026/11/21 22:29:53 by yabuhuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.c/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}					t_strategy;

typedef struct s_ops
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_ops;

typedef struct s_data
{
	t_list			*stack_a;
	t_list			*stack_b;
	t_strategy		mode;
	int				bench;
	int				size;
	double			disorder;
	const char		*strat_name;
	const char		*strat_class;
	t_ops			ops;
}					t_data;

int					ft_atoi(const char *str);
int					check_args(int ac, char **av);
int					has_duplicates(t_list *stack);
void				free_stack(t_list **stack);
t_list				*new_node(int value);
void				add_back(t_list **stack, t_list *new);
int					stack_size(t_list *stack);
int					is_sorted(t_list *stack);
int					init_list(t_data *data, int ac, char **av, int start);
void				sa(t_data *data);
void				sb(t_data *data);
void				ss(t_data *data);
void				pa(t_data *data);
void				pb(t_data *data);
void				ra(t_data *data);
void				rb(t_data *data);
void				rr(t_data *data);
void				rra(t_data *data);
void				rrb(t_data *data);
void				rrr(t_data *data);
double				compute_disorder(t_list *stack);
void				print_benchmark(t_data *data);
// yousef headr
int					rank_fun(t_list *stack);
void				two_val(t_data *head);
void				three_val(t_data *head);
void				five_val(t_data *head);
void				radix_sort(t_data *head);

#endif