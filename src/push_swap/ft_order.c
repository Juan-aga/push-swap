/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:35:29 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/22 16:21:09 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_utils.h"
#include <stdio.h>

static void	ft_first_push(t_ps *ps);
static void	ft_cost(t_ps *ps);
static void	ft_move(t_ps *ps, int cheap);
static void	ft_move_rest(t_ps *ps);

void	ft_order(t_ps *ps)
{
	int	i;

	ft_first_push(ps);
	ft_sort(ps);
	while (ps->stack_b)
	{
		ft_get_dest(ps);
		ft_cost(ps);
		ft_move(ps, INTMAX);
	}
	if (!(ft_isordened(ps->stack_a)))
	{
		i = ps->stack_a->index - 1;
		if (i <= ps->size_a / 2)
		{
			while (i--)
				ft_reverse(ps, 'a');
		}
		else
		{
			while (ps->stack_a->index != 1)
				ft_rotate(ps, 'a');
		}
	}
}

static void	ft_first_push(t_ps *ps)
{
	while (ps->size_a > 6 && ps->size_b < (ps->size_a + ps->size_b) / 2)
	{
		if (ps->stack_a->index <= (ps->size_a + ps->size_b) / 2)
			ft_push(ps, 'b');
		else
			ft_rotate(ps, 'a');
	}
	while (ps->size_a > 3)
		ft_push(ps, 'b');
}

static void	ft_cost(t_ps *ps)
{
	t_stack	*b;

	b = ps->stack_b;
	while (b)
	{
		b->cost_b = b->pos;
		if (b->pos > ps->size_b / 2)
			b->cost_b = (ps->size_b - b->pos) * -1;
		b->cost_a = b->dest;
		if (b->dest > ps->size_a / 2)
			b->cost_a = (ps->size_a - b->dest) * -1;
		b = b->next;
	}
}

static void	ft_move(t_ps *ps, int cheap)
{
	t_stack	*tmp;

	tmp = ps->stack_b;
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < ft_abs(cheap))
		{
			cheap = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
			ps->cheap_a = tmp->cost_a;
			ps->cheap_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	if (ps->cheap_a < 0 && ps->cheap_b < 0)
		ft_reverse(ps, 'r');
	else if (ps->cheap_a > 0 && ps->cheap_b > 0)
		ft_rotate(ps, 'r');
	ft_move_rest(ps);
	ft_push(ps, 'a');
}

static void	ft_move_rest(t_ps *ps)
{
	if (ps->cheap_a < 0)
	{
		while (ps->cheap_a)
			ft_reverse(ps, 'a');
	}
	else if (ps->cheap_a > 0)
	{
		while (ps->cheap_a)
			ft_rotate(ps, 'a');
	}
	if (ps->cheap_b < 0)
	{
		while (ps->cheap_b)
			ft_reverse(ps, 'b');
	}
	else if (ps->cheap_b > 0)
	{
		while (ps->cheap_b)
			ft_rotate(ps, 'b');
	}
}
