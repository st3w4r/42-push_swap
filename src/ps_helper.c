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

int		ps_stack_empty(t_stack **stack)
{
	if (stack && *stack)
		return (1);
	return (0);
}

void	ps_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr(stack->nbr);
		ft_putstr(" ");
		stack = stack->down;
	}
}

void	ps_print_operation_color(t_env *env)
{
	if (env->flags & FLAGS_C)
	{
		ft_putendl("Stack a");
		ft_putstr("\033[1;31m");
		ps_print_stack(env->stack_a);
		ft_putstr("\033[0m");
		ft_putendl("\nStack b");
		ft_putstr("\033[1;33m");
		ps_print_stack(env->stack_b);
		ft_putstr("\033[0m\n\n");
	}
	else
	{
		ft_putendl("Stack a");
		ps_print_stack(env->stack_a);
		ft_putendl("\nStack b");
		ps_print_stack(env->stack_b);
		ft_putstr("\n\n");
	}
}

void	ps_print_operation(t_env *env, char *str)
{
	if (!(env->flags & FLAGS_M) && !(env->flags & FLAGS_V))
	{
		if (env->nb_ops != 0)
			ft_putstr(" ");
		ft_putstr(str);
	}
	if (env->flags & FLAGS_V)
	{
		if (!(env->flags & FLAGS_M))
			ft_putstr("\033[1;37m"), ft_putstr(str), ft_putstr("\033[0m\n");
		ps_print_operation_color(env);
	}
	env->nb_ops += 1;
}

int		ps_stack_is_sorted(t_stack *stack, int reverse)
{
	while (stack && stack->down)
	{
		if (reverse)
		{
			if ((stack->nbr) < (stack->down->nbr))
				return (0);
		}
		else
		{
			if ((stack->nbr) > (stack->down->nbr))
				return (0);
		}
		stack = stack->down;
	}
	return (1);
}
