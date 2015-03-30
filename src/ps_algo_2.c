/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 16:19:52 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/27 16:19:54 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_swap_end_op(t_env *env)
{
	ps_operator_rra(env, 1);
	ps_operator_rra(env, 1);
	ps_operator_sa(env, 1);
	ps_operator_ra(env, 1);
	ps_operator_ra(env, 1);
}

void		ps_push_reverse(t_env *env)
{
	while (ps_stack_empty(&(env->stack_a)))
	{
		ps_operator_pb(env, 1);
		ps_operator_rb(env, 1);
	}
	while (ps_stack_empty(&(env->stack_b)))
	{
		ps_operator_pa(env, 1);
	}
}

int			ps_swap_end(t_stack *stack)
{
	while (stack->down->down)
	{
		stack = stack->down;
	}
	if (stack->nbr > stack->down->nbr)
		return (1);
	return (0);
}

int			ps_algo_optimize(t_env *env)
{
	int optimized;
	int size;

	optimized = 0;
	size = ps_stack_size(env->stack_a);
	if (ps_stack_is_sorted(env->stack_a, 0) == 1)
		return (1);
	if (size == 2)
		ps_operator_sa(env, 1), optimized = 1;
	if (size == 3)
		ps_algo_optimize_three(env), optimized = 1;
	if (size == 5)
		ps_algo_optimize_five(env, size);
	if (ps_stack_is_sorted(env->stack_a, 1) == 1)
	{
		ps_push_reverse(env);
		return (1);
	}
	if (env->stack_a->nbr > env->stack_a->down->nbr)
		ps_operator_sa(env, 1);
	if (ps_swap_end(env->stack_a))
		ps_swap_end_op(env);
	return (optimized);
}
