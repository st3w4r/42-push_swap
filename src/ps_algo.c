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

/*
static int		ps_next_swap(t_stack *stack)
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

	ft_putnbr(count_rotate);
	if (count_rotate < size_mid_stack)
		return (-1); //RRA
	else
		return (1); //RA
}*/

static int		ps_next_swap(t_stack *stack)
{
	int size_mid_stack;
	int pos_swap;

	size_mid_stack = (ps_stack_size(stack) / 2);

	pos_swap = 0;
	while (stack->down)
	{
		if (stack->down->nbr < stack->nbr)
			break ;
		++pos_swap;
		stack = stack->down;
	}
	return ((pos_swap < size_mid_stack) ? 1 : -1);
}

static int		ps_next_swap_b(t_stack *stack)
{
	int size_mid_stack;
	int pos_swap;

	size_mid_stack = (ps_stack_size(stack) / 2);

	pos_swap = 0;
	while (stack->down)
	{
		if (stack->down->nbr > stack->nbr)
			break ;
		++pos_swap;
		stack = stack->down;
	}
	return ((pos_swap < size_mid_stack) ? 1 : -1);
}


static void ps_sort_bubble(int *arr, int size)
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
				arr[j] = arr[j +1];
				arr[j + 1] = tmp;
				state = 1;
			}
			++j;
		}
		--i;
	}
}

static int ps_stack_mid(t_stack *stack)
{
	int *arr;
	int size;
	int i;
	int res;

	size = ps_stack_size(stack);
	if (!(arr = (int*)malloc(sizeof(int) * size)))
		ft_malloc_error();
	i = 0;
	while (i < size)
	{
		arr[i] = stack->nbr;
		stack = stack->down;
		++i;
	}
	ps_sort_bubble(arr, size);
	i = 0;
	while (i < size / 2)
		++i;
	res = arr[i];
	free(arr);
	return (res);
}
/*
static void	ps_push_nb(t_env *env, int nb_push, char name_stack, int mid)
{
	int i;

	i = 0;

	// ft_putnbr(mid);
	while (i < nb_push)
	{
		// ft_putnbr(i);

		if (name_stack == 'a')
		{
			// if (ps_stack_peek(&(env->stack_b))->nbr > mid)
				ps_operator_pa(env, 1);
		}
		else if (name_stack == 'b')
		{
			ft_putnbr(env->stack_a->nbr);
			if (env->stack_a->nbr < mid)
			{

				ft_putendl("In");
				ps_operator_pb(env, 1);

			}else
				ft_putendl("Outr");

		}
		++i;
	}
}
*/
static void	ps_push_nb(t_env *env, int nb_push, int mid)
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


void	ps_algo_sort(t_env *env)
{
	int min;
	int max;
	int mid;
	int state;
	int size;
	// int size_mid_stack;


	if (ps_stack_empty(&(env->stack_a)) == 0)
		return ;

	// size_mid_stack = (ps_stack_size(env->stack_a) / 2);
	size = ps_stack_size(env->stack_a);

	mid = ps_stack_mid(env->stack_a);

	ps_push_nb(env, size, mid);
	// ps_push_nb(env, size_mid_stack, 'a');

	min = ps_min_stack(env->stack_a);
	// max = ps_max_stack(env->stack_b);

	state = ps_next_swap(env->stack_a);


	while (ps_stack_is_sorted(env->stack_a, 0) == 0)
	{
		if (!env->stack_a->down)
			return ;

		if (env->stack_a->down->nbr != min &&
			env->stack_a->down->nbr < env->stack_a->nbr)
		{
			ps_operator_sa(env,1);
			state = ps_next_swap(env->stack_a);
		}

		state == 1 ? ps_operator_ra(env, 1) : ps_operator_rra(env, 1);
	}

if (!env->stack_b)
	return ;
	max = ps_max_stack(env->stack_b);

	state = ps_next_swap(env->stack_b);
	while (ps_stack_is_sorted(env->stack_b, 1) == 0)
	{
		if (!env->stack_b->down)
			return ;

		if (env->stack_b->down->nbr != max &&
			env->stack_b->down->nbr > env->stack_b->nbr)
		{
			ps_operator_sb(env,1);
			state = ps_next_swap_b(env->stack_b);
		}
		state == 1 ? ps_operator_rb(env, 1) : ps_operator_rrb(env, 1);
	}

	while (ps_stack_empty(&(env->stack_b)))
		ps_operator_pa(env, 1);
	// ps_push_nb(env, size, 'a', mid);
}
