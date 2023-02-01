/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:09:38 by juan-aga          #+#    #+#             */
/*   Updated: 2023/01/23 22:12:39 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	ft_error(t_ps *ps)
{
	if (ps->ac == 2)
		ft_free_array(ps->av);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
