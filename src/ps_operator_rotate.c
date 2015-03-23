/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operator_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 11:22:33 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/23 11:22:34 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Name: ra
** Desc: rotate a - décale d’une position tous les élements de la pile a.
** (vers le haut, le premier élément devient le dernier).
*/
void	ps_operator_ra(t_env *env, int is_print)
{
	t_stack *elem_tmp;
	t_stack *elem_tmp_2;

	if (!env || !(env->stack_a) || !(env->stack_a->down))
		return ;
	elem_tmp = ps_stack_peek(&(env->stack_a)); // Save ptr a;
	elem_tmp_2 = ps_stack_peek(&(env->stack_a)); // Save ptr a;
	while (elem_tmp_2->down) // Recuperer le dernier elem
		elem_tmp_2 = elem_tmp_2->down;
	elem_tmp_2->down = elem_tmp;
	env->stack_a = elem_tmp->down;
	elem_tmp->down = NULL;

	if (is_print)
		ft_putendl("ra");
}

/*
** Name: rb
** Desc: rotate b - décale d’une position tous les élements de la pile b.
** (vers le haut, le premier élément devient le dernier).
*/
void	ps_operator_rb(t_env *env, int is_print)
{
	t_stack *elem_tmp;
	t_stack *elem_tmp_2;

	if (!env || !(env->stack_b) || !(env->stack_b->down))
		return ;
	elem_tmp = ps_stack_peek(&(env->stack_b)); // Save ptr a;
	elem_tmp_2 = ps_stack_peek(&(env->stack_b)); // Save ptr a;
	while (elem_tmp_2->down) // Recuperer le dernier elem
		elem_tmp_2 = elem_tmp_2->down;
	elem_tmp_2->down = elem_tmp;
	env->stack_b = elem_tmp->down;
	elem_tmp->down = NULL;

	if (is_print)
		ft_putendl("ra");
}

/*
** Name: rr
** Desc: ra et rb en meme temps.
** (vers le haut, le premier élément devient le dernier).
*/
void	ps_operator_rr(t_env *env, int is_print)
{
	if (!env || !(env->stack_a) || !(env->stack_b))
		return ;
	ps_operator_ra(env, 0);
	ps_operator_rb(env, 0);
	if (is_print)
		ft_putendl("rr");
}
