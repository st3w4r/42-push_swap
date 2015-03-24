/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 21:15:36 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/23 21:15:37 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ps_min_stack(t_stack *stack)
{
	int min;

	min = stack->nbr;
	while (stack)
	{
		if (min > stack->nbr)
			min = stack->nbr;
		stack = stack->down;
	}
	return (min);
}

static int		ps_max_stack(t_stack *stack)
{
	int max;

	max = stack->nbr;
	while (stack)
	{
		if (max < stack->nbr)
			max = stack->nbr;
		stack = stack->down;
	}
	return (max);
}

int		ps_ra_rra(t_stack *stack)
{
	int size_mid_stack;
	int count_rotate;

	size_mid_stack = (ps_stack_size(stack) / 2);

	count_rotate = 0;
	while (stack->down)
	{
		if (stack->down->nbr > stack->nbr)
			++count_rotate;
		stack = stack->down;
	}

	// ft_putnbr(count_rotate);
	if (count_rotate < size_mid_stack)
		return (-1); //RRA
	else
		return (1); //RA
}

void	ps_algo_sort(t_env *env)
{
	// int max;
	int min;
	int state;

	if (ps_stack_empty(&(env->stack_a)) == 0)
		return ;
	min = ps_min_stack(env->stack_a);
	while (ps_stack_is_sorted(env->stack_a) == 0)
	{
		if (!env->stack_a->down)
			return ;

		if (env->stack_a->down->nbr != min &&
			env->stack_a->down->nbr < env->stack_a->nbr)
		{
			ps_operator_sa(env,1);
			state = ps_ra_rra(env->stack_a);
		}

		if (state)
		{
			ps_ra_rra(env->stack_a);
			ps_ra_rra(env->stack_a);
		}

		ps_operator_ra(env, 1);
		ps_operator_rra(env, 1);
	}
}
