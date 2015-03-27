/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 16:20:00 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/27 16:20:02 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_min_stack(t_stack *stack)
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

int		ps_max_stack(t_stack *stack)
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

int		ps_stack_mid(t_stack *stack)
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

int		ps_next_swap(t_stack *stack)
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

int		ps_next_swap_b(t_stack *stack)
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
