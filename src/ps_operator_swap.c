/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operator_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 10:09:55 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/23 10:09:57 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_operator_sa(t_env *env, int is_print)
{
	if (!env || !(env->stack_a) || !(env->stack_a->down))
		return ;
	ps_stack_swap_top(&(env->stack_a));
	if (is_print)
		ps_print_operation(env, "sa");
}

void		ps_operator_sb(t_env *env, int is_print)
{
	if (!env || !(env->stack_b) || !(env->stack_b->down))
		return ;
	ps_stack_swap_top(&(env->stack_b));
	if (is_print)
		ps_print_operation(env, "sb");
}

void		ps_operator_ss(t_env *env, int is_print)
{
	if (!env || !(env->stack_a) || !(env->stack_b))
		return ;
	ps_operator_sa(env, 0);
	ps_operator_sb(env, 0);
	if (is_print)
		ps_print_operation(env, "ss");
}
