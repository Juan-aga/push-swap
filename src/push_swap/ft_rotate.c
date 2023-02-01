/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:05:43 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/24 14:48:36 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void	rotate(t_stack **s, int size);
static void	reverse(t_stack **s, int size);

void	ft_rotate(t_ps *ps, char move)
{
	if (move == 'r')
	{
		rotate(&ps->stack_a, ps->size_a);
		rotate(&ps->stack_b, ps->size_b);
		ps->cheap_a -= 1;
		ps->cheap_b -= 1;
	}
	else if (move == 'a')
	{
		rotate(&ps->stack_a, ps->size_a);
		ps->cheap_a -= 1;
	}
	else if (move == 'b')
	{
		rotate(&ps->stack_b, ps->size_b);
		ps->cheap_b -= 1;
	}
	else
		ft_error(ps);
	if (!ps->param)
		ft_printf("r%c\n", move);
}

void	ft_reverse(t_ps *ps, char move)
{
	if (move == 'r')
	{
		reverse(&ps->stack_a, ps->size_a);
		reverse(&ps->stack_b, ps->size_b);
		ps->cheap_a += 1;
		ps->cheap_b += 1;
	}
	else if (move == 'a')
	{
		reverse(&ps->stack_a, ps->size_a);
		ps->cheap_a += 1;
	}
	else if (move == 'b')
	{
		reverse(&ps->stack_b, ps->size_b);
		ps->cheap_b += 1;
	}
	else
		ft_error(ps);
	if (!ps->param)
		ft_printf("rr%c\n", move);
}

static void	rotate(t_stack **s, int size)
{
	t_stack	*tmp;
	t_stack	*last;

	if (size <= 1)
		return ;
	tmp = *s;
	*s = (*s)->next;
	last = ft_stacklast(*s);
	tmp->next = NULL;
	last->next = tmp;
}

static void	reverse(t_stack **s, int size)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*prelast;

	if (size <= 1)
		return ;
	last = ft_stacklast(*s);
	prelast = ft_stackprelast(*s);
	tmp = *s;
	*s = last;
	(*s)->next = tmp;
	prelast->next = NULL;
}
