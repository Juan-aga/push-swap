/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:28:15 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/22 14:47:28 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int nb)
{
	t_stack	*stack;

	stack = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->number = nb;
	stack->index = 0;
	stack->pos = -1;
	stack->dest = -1;
	stack->cost_a = -1;
	stack->cost_b = -1;
	stack->next = NULL;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *add)
{
	t_stack	*last;

	if (!stack || !add)
		return ;
	if (!*stack)
	{
		*stack = add;
		return ;
	}
	last = ft_stacklast(*stack);
	last->next = add;
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	if (stack)
	{
		while (last->next)
			last = last->next;
	}
	return (last);
}

t_stack	*ft_stackprelast(t_stack *stack)
{
	t_stack	*prelast;

	prelast = stack;
	if (stack)
	{
		while (prelast->next->next)
			prelast = prelast->next;
	}
	return (prelast);
}

void	ft_free_stack(t_ps *ps)
{
	t_stack	*tmp;

	if (ps->stack_a)
	{
		while (ps->stack_a)
		{
			tmp = ps->stack_a->next;
			free(ps->stack_a);
			ps->stack_a = tmp;
		}
		free(ps->stack_a);
	}
	if (ps->stack_b)
	{
		while (ps->stack_b)
		{
			tmp = ps->stack_b->next;
			free(ps->stack_b);
			ps->stack_b = tmp;
		}
		free(ps->stack_b);
	}
	if (ps->param)
		ft_free_array(ps->param);
}
