/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 19:59:58 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/22 19:59:59 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stack_push(t_stack **stack, t_stack *elem)
{
	if (!stack || !elem)
		return ;
	elem->down = *stack;
	*stack = elem;
}

t_stack	*ps_stack_pop(t_stack **stack)
{
	t_stack *elem;

	if (!stack || !(*stack))
		return (NULL);
	elem = *stack;
	*stack = (*stack)->down;
	return (elem);
}

int		ps_stack_empty(t_stack **stack)
{
	if (stack && *stack)
		return (1);
	return (0);
}

t_stack	*ps_stack_peek(t_stack **stack)
{
	if (!stack || !(*stack))
		return (NULL);
	return (*stack);
}

void	ps_stack_swap_top(t_stack **stack)
{
	t_stack *ptr_tmp;

	if (!stack || !(*stack))
		return ;
	ptr_tmp = (*stack)->down; // Save Ptr b
	(*stack)->down = (*stack)->down->down; // Change ptr down de a avec ptr down de b
	ptr_tmp->down = *stack; // Change le ptr down de b avec le ptr sur a
	*stack = ptr_tmp; // Change le ptr TOP avec le ptr sur b
}
