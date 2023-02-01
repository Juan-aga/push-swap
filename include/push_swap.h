/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:29:22 by juan-aga          #+#    #+#             */
/*   Updated: 2023/02/01 15:37:09 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_utils.h"

# define INTMAX 2147483647 
# define INTMIN -2147483648

typedef struct s_stack
{
	int				number;
	int				index;
	int				pos;
	int				dest;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ps
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				ac;
	char			**av;
	char			**param;
	int				size_a;
	int				size_b;
	int				cheap_a;
	int				cheap_b;
}	t_ps;

void	ft_check_args(t_ps *ps);
void	ft_free_array(char **av);
void	ft_error(t_ps *ps);
/*		stacks		*/
void	ft_init_stack(t_ps *ps);
t_stack	*ft_stacknew(int nb);
void	ft_stackadd_back(t_stack **stack, t_stack *add);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stackprelast(t_stack *stack);
void	ft_free_stack(t_ps *ps);
/*		utils		*/
int		ft_isordened(t_stack *a);
void	ft_sort(t_ps *ps);
void	ft_order(t_ps *ps);
void	ft_get_dest(t_ps *ps);

/*		movements	*/
void	ft_swap(t_ps *ps, char move);
void	ft_rotate(t_ps *ps, char move);
void	ft_reverse(t_ps *ps, char move);
void	ft_push(t_ps *ps, char move);

#endif
