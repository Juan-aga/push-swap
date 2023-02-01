/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:58:56 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/21 03:54:51 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_number(char *c);
static int	ft_limits(char *c);

void	ft_check_args(t_ps *ps)
{
	int	i;

	i = -1;
	while (ps->av[++i])
	{
		if (!(ft_check_number(ps->av[i])))
			ft_error(ps);
	}
}

void	ft_free_array(char **av)
{
	int	i;

	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
}

/*	check if is a number and is in the int limits.
 *	return 1 if is a number, 
 *	else return 0;
 */
static int	ft_check_number(char *c)
{
	int	i;

	i = 0;
	if (ft_issign(c[i]))
		i++;
	while (ft_isdigit(c[i]))
		i++;
	if (c[i] != '\0' || ft_issign(c[i - 1]))
		return (0);
	if (!(ft_limits(c)))
		return (0);
	return (1);
}

/*	check if the number is in the int limits.
 *	return 1 if true
 *	else return 0;
 */
static int	ft_limits(char *c)
{
	long long	tmp;

	tmp = ft_atoll(c);
	if (tmp < INTMIN || tmp > INTMAX)
		return (0);
	return (1);
}
