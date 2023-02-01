/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:14:44 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/22 16:58:53 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_repeat(t_stack *stack, int nb);
static void	ft_index(t_stack **a, int size);

void	ft_init_stack(t_ps *ps)
{
	int		i;
	int		nb;

	ps->stack_a = NULL;
	ps->stack_b = NULL;
	i = -1;
	while (ps->av[++i])
	{
		nb = ft_atoi(ps->av[i]);
		if (i == 0)
			ps->stack_a = ft_stacknew(nb);
		else
		{
			if (!(ft_is_repeat(ps->stack_a, nb)))
				ft_stackadd_back(&ps->stack_a, ft_stacknew(nb));
			else
				ft_error(ps);
		}
	}
	if (ps->ac == 2)
		ft_free_array(ps->av);
	ps->ac = 1;
	ps->size_a = i;
	ps->size_b = 0;
	ft_index(&ps->stack_a, i + 1);
}

static int	ft_is_repeat(t_stack *stack, int nb)
{
	t_stack	*check;

	check = stack;
	while (check)
	{
		if (check->number == nb)
			return (1);
		check = check->next;
	}
	return (0);
}

static void	ft_index(t_stack **a, int size)
{
	t_stack	*tmp;
	t_stack	*last;
	int		index;

	while (--size > 0)
	{
		tmp = *a;
		last = NULL;
		index = INTMIN;
		while (tmp)
		{
			if (tmp->number == INTMIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->number > index && tmp->index == 0)
			{
				index = tmp->number;
				last = tmp;
				tmp = *a;
			}
			else
				tmp = tmp->next;
		}
		if (last != NULL)
			last->index = size;
	}
}
