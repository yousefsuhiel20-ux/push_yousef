/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuhuss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 22:30:18 by yabuhuss          #+#    #+#             */
/*   Updated: 2026/11/21 22:52:14 by yabuhuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	percent_fun(double disorder, int fd)
{
	long	precent_100;
	long	before_dot;
	long	after_dot;

	if (disorder < 0.0)
		disorder = 0.0;
	if (disorder > 1.0)
		disorder = 1.0;
	precent_100 = (long)(disorder * 10000.0 + 0.5);
	before_dot = precent_100 / 100;
	after_dot = precent_100 % 100;
	ft_putnbr_fd((int)before_dot, fd);
	write(fd, ".", 1);
	if (after_dot < 10)
		write(fd, "0", 1);
	ft_putnbr_fd((int)after_dot, fd);
	write(fd, "%\n", 2);
}

static void	print_ops_counts(t_ops *ops, int fd)
{
	ft_putstr_fd("[bench] total_ops: ", fd);
	ft_putnbr_fd(ops->total, fd);
	write(fd, "\n[bench] sa: ", 13);
	ft_putnbr_fd(ops->sa, fd);
	ft_putstr_fd(" sb: ", fd);
	ft_putnbr_fd(ops->sb, fd);
	ft_putstr_fd(" ss: ", fd);
	ft_putnbr_fd(ops->ss, fd);
	ft_putstr_fd(" pa: ", fd);
	ft_putnbr_fd(ops->pa, fd);
	ft_putstr_fd(" pb: ", fd);
	ft_putnbr_fd(ops->pb, fd);
	write(fd, "\n[bench] ra: ", 13);
	ft_putnbr_fd(ops->ra, fd);
	ft_putstr_fd(" rb: ", fd);
	ft_putnbr_fd(ops->rb, fd);
	ft_putstr_fd(" rr: ", fd);
	ft_putnbr_fd(ops->rr, fd);
	ft_putstr_fd(" rra: ", fd);
	ft_putnbr_fd(ops->rra, fd);
	ft_putstr_fd(" rrb: ", fd);
	ft_putnbr_fd(ops->rrb, fd);
	ft_putstr_fd(" rrr: ", fd);
	ft_putnbr_fd(ops->rrr, fd);
	write(fd, "\n", 1);
}

void	print_bench(t_data *data)
{
	if (!data || !data->bench)
		return ;
	ft_putstr_fd("[bench] disorder: ", 2);
	percent_fun(data->disorder, 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd((char *)data->strat_name, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd((char *)data->strat_class, 2);
	write(2, "\n", 1);
	print_ops_counts(&data->ops, 2);
}
