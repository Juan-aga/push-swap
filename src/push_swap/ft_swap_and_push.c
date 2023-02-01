/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_and_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:32:41 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/23 21:24:45 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void	swap(t_stack **s);
static void	push(t_stack **s, t_stack **d);

void	ft_swap(t_ps *ps, char move)
{
	if (move == 's')
	{
		swap(&ps->stack_a);
		swap(&ps->stack_b);
	}
	else if (move == 'a')
		swap(&ps->stack_a);
	else if (move == 'b')
		swap(&ps->stack_b);
	else
		ft_error(ps);
	if (!ps->param)
		ft_printf("s%c\n", move);
}

void	ft_push(t_ps *ps, char move)
{
	if (move == 'a')
	{
		push(&ps->stack_b, &ps->stack_a);
		ps->size_a += 1;
		ps->size_b -= 1;
	}
	else if (move == 'b')
	{
		push(&ps->stack_a, &ps->stack_b);
		ps->size_a -= 1;
		ps->size_b += 1;
	}
	else
		ft_error(ps);
	if (!ps->param)
		ft_printf("p%c\n", move);
}

static void	swap(t_stack **s)
{
	int	tmp;

	if (*s == NULL || (*s)->next == NULL)
		return ;
	tmp = (*s)->number;
	(*s)->number = (*s)->next->number;
	(*s)->next->number = tmp;
	tmp = (*s)->index;
	(*s)->index = (*s)->next->index;
	(*s)->next->index = tmp;
}

static void	push(t_stack **s, t_stack **d)
{
	t_stack	*tmp;

	if (!*s)
		return ;
	tmp = (*s)->next;
	(*s)->next = *d;
	*d = *s;
	*s = tmp;
}
