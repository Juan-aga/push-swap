/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:18:37 by juan-aga          #+#    #+#             */
/*   Updated: 2023/02/01 15:35:08 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include <stdlib.h>

static void	ft_start(t_ps *ps);

int	main(int ac, char **av)
{
	t_ps	ps;

	ps.ac = ac;
	ps.av = &av[1];
	ps.param = NULL;
	if (ac < 2)
		return (1);
	if (ac == 2)
		ps.av = ft_split(ps.av[0], ' ');
	ft_check_args(&ps);
	ft_init_stack(&ps);
	ft_start(&ps);
	ft_free_stack(&ps);
	return (0);
}

static void	ft_start(t_ps *ps)
{
	ps->cheap_a = 0;
	ps->cheap_b = 0;
	if (ps->size_a == 2 && !(ft_isordened(ps->stack_a)))
		ft_swap(ps, 'a');
	else if (ps->size_a == 3)
		ft_sort(ps);
	else if (ps->size_a > 3 && !(ft_isordened(ps->stack_a)))
		ft_order(ps);
}
