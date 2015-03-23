/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operator_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 10:56:33 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/23 10:56:36 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Name: pa
** Desc: push a - prend le premier élément au sommet de b et le met sur a.
** (ne fait rien si b est vide).
*/
void	ps_operator_pa(t_env *env, int is_print)
{
	t_stack *elem;

	elem = NULL;
	if (!env || !(env->stack_b))
		return ;
	elem = ps_stack_pop(&(env->stack_b));
	ps_stack_push(&(env->stack_a), elem);
	if (is_print)
		ft_putendl("pa");
}

/*
** Name: pb
** Desc: push b - prend le premier élément au sommet de a et le met sur b.
** (ne fait rien si b est vide).
*/
void	ps_operator_pb(t_env *env, int is_print)
{
	t_stack *elem;

	elem = NULL;
	if (!env || !(env->stack_a))
		return ;
	elem = ps_stack_pop(&(env->stack_a));
	ps_stack_push(&(env->stack_b), elem);
	if (is_print)
		ft_putendl("pb");
}
