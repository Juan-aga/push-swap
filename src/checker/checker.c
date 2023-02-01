/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:01:25 by juan-aga          #+#    #+#             */
/*   Updated: 2023/02/01 15:40:26 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <stdio.h>
#include "fractol_utils.h"

static void	ft_take_order(t_ps *ps);
static void	ft_check(t_ps *ps);

int	main(int ac, char **av)
{
	t_ps	ps;

	ps.ac = ac;
	ps.av = &av[1];
	if (ac == 1)
		return (0);
	if (ac == 2)
		ps.av = ft_split(ps.av[0], ' ');
	ft_check_args(&ps);
	ft_init_stack(&ps);
	ft_take_order(&ps);
	if (ft_isordened(ps.stack_a) && ps.size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_stack(&ps);
	return (0);
}

static void	ft_take_order(t_ps *ps)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_calloc(sizeof(char *), 1);
	tmp = get_next_line(0);
	str = NULL;
	while (tmp)
	{
		str = ft_strjoin(tmp2, tmp);
		free(tmp2);
		tmp2 = str;
		free(tmp);
		tmp = get_next_line(0);
	}
	if (!str)
	{
		if (tmp2)
			free(tmp2);
		return ;
	}
	ps->param = ft_split(str, '\n');
	free(str);
	ft_check(ps);
}

static void	ft_check(t_ps *ps)
{
	int	i;
	int	l;

	i = 0;
	while (ps->param[i])
	{
		l = ft_strlen(ps->param[i]);
		if (ps->param[i][0] == 'r' && l <= 3)
		{
			if (ps->param[i][2])
				ft_reverse(ps, ps->param[i][2]);
			else
				ft_rotate(ps, ps->param[i][1]);
		}
		else if (ps->param[i][0] == 's' && l <= 2)
			ft_swap(ps, ps->param[i][1]);
		else if (ps->param[i][0] == 'p' && l <= 2)
			ft_push(ps, ps->param[i][1]);
		else
			ft_error(ps);
		i++;
	}
}
