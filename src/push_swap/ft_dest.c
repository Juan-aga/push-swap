/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:58:18 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/21 03:55:20 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_position(t_stack **s);
static int	ft_dest(t_stack **a, int index_b, int index_a, int dest);
static int	ft_dest2(t_stack **a, int index_a, int dest);

void	ft_get_dest(t_ps *ps)
{
	t_stack	*tmp;
	int		dest;

	tmp = ps->stack_b;
	ft_position(&ps->stack_a);
	ft_position(&ps->stack_b);
	dest = 0;
	while (tmp)
	{
		dest = ft_dest(&ps->stack_a, tmp->index, INTMAX, dest);
		tmp->dest = dest;
		tmp = tmp->next;
	}
}

static void	ft_position(t_stack **s)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *s;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int	ft_dest(t_stack **a, int index_b, int index_a, int dest)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < index_a)
		{
			index_a = tmp->index;
			dest = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (index_a != INTMAX)
		return (dest);
	else
		return (ft_dest2(a, index_a, dest));
}

static int	ft_dest2(t_stack **a, int index_a, int dest)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index < index_a)
		{
			index_a = tmp->index;
			dest = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (dest);
}
