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

void			ps_sort_bubble(int *arr, int size)
{
	int state;
	int i;
	int j;
	int tmp;

	i = size - 1;
	state = 1;
	while (i > 0 && state)
	{
		state = 0;
		j = 0;
		while (j < i)
		{
			if (arr[j] >= arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				state = 1;
			}
			++j;
		}
		--i;
	}
}

void			ps_push_nb(t_env *env, int nb_push, int mid)
{
	int i;

	i = 0;
	while (i < nb_push)
	{
		if (ps_stack_peek(&(env->stack_a))->nbr < mid)
			ps_operator_pb(env, 1);
		ps_operator_rra(env, 1);
		++i;
	}
}

static void		ps_algo_sort_b(t_env *env)
{
	int max;
	int state;

	max = ps_max_stack(env->stack_b);
	state = ps_next_swap(env->stack_b);
	while (ps_stack_is_sorted(env->stack_b, 1) == 0)
	{
		if (!env->stack_b->down)
			return ;
		if (env->stack_b->down->nbr != max &&
			env->stack_b->down->nbr > env->stack_b->nbr)
		{
			ps_operator_sb(env, 1);
			state = ps_next_swap_b(env->stack_b);
		}
		state == 1 ? ps_operator_rb(env, 1) : ps_operator_rrb(env, 1);
	}
	while (ps_stack_empty(&(env->stack_b)))
		ps_operator_pa(env, 1);
}

void			ps_algo_sort(t_env *env, int state)
{
	int min;
	int mid;
	int size;

	size = ps_stack_size(env->stack_a);
	mid = ps_stack_mid(env->stack_a);
	if (ps_algo_optimize(env) == 1)
		return ;
	if (ps_stack_is_sorted(env->stack_a, 0) == 0 && size > 5)
		ps_push_nb(env, size, mid);
	min = ps_min_stack(env->stack_a);
	state = ps_next_swap(env->stack_a);
	while (ps_stack_is_sorted(env->stack_a, 0) == 0)
	{
		if (!env->stack_a->down)
			return ;
		if (env->stack_a->down->nbr != min &&
			env->stack_a->down->nbr < env->stack_a->nbr)
		{
			ps_operator_sa(env, 1);
			state = ps_next_swap(env->stack_a);
		}
		state == 1 ? ps_operator_ra(env, 1) : ps_operator_rra(env, 1);
	}
	if (env->stack_b)
		ps_algo_sort_b(env);
}
