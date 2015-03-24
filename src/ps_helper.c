/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 10:39:02 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/23 10:39:03 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr(stack->nbr);
		ft_putendl("");
		stack = stack->down;
	}
}

void	ps_print_operation(t_env *env, char *str)
{
	if (!(env->flags & FLAGS_M))
	{
		if (env->nb_ops != 0)
			ft_putstr(" ");
		ft_putstr(str);
	}
	env->nb_ops += 1;
}

int		ps_cmp_int(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (1);
	return (0);
}

int		ps_stack_is_sorted(t_stack *stack)
{
	while (stack->down)
	{
		if ((stack->nbr) > (stack->down->nbr))
			return (0);
		stack = stack->down;
	}
	return (1);
}
