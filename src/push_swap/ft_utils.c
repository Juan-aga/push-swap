/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:28:27 by juan-aga          #+#    #+#             */
/*   Updated: 2023/02/01 15:36:30 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return 1 if it is ordened
 * else returns 0
 */
int	ft_isordened(t_stack *a)
{
	while (a->next)
	{
		if (a->number > a->next->number)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_sort(t_ps *ps)
{
	int		last;
	t_stack	*a;

	a = ps->stack_a;
	if (ft_isordened(ps->stack_a))
		return ;
	last = ps->stack_a->index;
	while (a)
	{
		if (a->index > last)
			last = a->index;
		a = a->next;
	}
	if (ps->stack_a->index == last)
		ft_rotate(ps, 'a');
	else if (ps->stack_a->next->index == last)
		ft_reverse(ps, 'a');
	if (ps->stack_a->index > ps->stack_a->next->index)
		ft_swap(ps, 'a');
}
