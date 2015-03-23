/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operator_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:25:37 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/23 17:25:39 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Name: rra
** Desc: reverse rotate a - décale d’une position tous les élements de la pile a.
** (vers le bas, le dernier élément devient le premier).
*/
void	ps_operator_rra(t_env *env, int is_print)
{
	t_stack *elem_tmp;
	t_stack *elem_tmp_2;

	if (!env || !(env->stack_a) || !(env->stack_a->down))
		return ;
	elem_tmp = ps_stack_peek(&(env->stack_a)); // Save ptr a;
	elem_tmp_2 = ps_stack_peek(&(env->stack_a)); // Save ptr a;
	while (elem_tmp_2->down->down) //Recuperer l'avant dernier
		elem_tmp_2 = elem_tmp_2->down;

	elem_tmp_2->down->down = elem_tmp; // Mettre le down du dernier sur le 1er
	env->stack_a = elem_tmp_2->down; // Mettre le TOP sur le dernier
	elem_tmp_2->down = NULL;

	if (is_print)
		ft_putendl("rra");
}

/*
** Name: rrb
** Desc: reverse rotate b - décale d’une position tous les élements de la pile b.
** (vers le bas, le dernier élément devient le premier).
*/
void	ps_operator_rrb(t_env *env, int is_print)
{
	t_stack *elem_tmp;
	t_stack *elem_tmp_2;

	if (!env || !(env->stack_b) || !(env->stack_b->down))
		return ;
	elem_tmp = ps_stack_peek(&(env->stack_b)); // Save ptr a;
	elem_tmp_2 = ps_stack_peek(&(env->stack_b)); // Save ptr a;
	while (elem_tmp_2->down->down) //Recuperer l'avant dernier
		elem_tmp_2 = elem_tmp_2->down;

	elem_tmp_2->down->down = elem_tmp; // Mettre le down du dernier sur le 1er
	env->stack_b = elem_tmp_2->down; // Mettre le TOP sur le dernier
	elem_tmp_2->down = NULL;

	if (is_print)
		ft_putendl("rrb");
}

/*
** Name: rrb
** Desc: reverse rotate b - décale d’une position tous les élements de la pile b.
** (vers le bas, le dernier élément devient le premier).
*/
void	ps_operator_rrr(t_env *env, int is_print)
{
	if (!env || !(env->stack_a) || !(env->stack_b))
		return ;
	ps_operator_rra(env, 0);
	ps_operator_rrb(env, 0);
	if (is_print)
		ft_putendl("rrr");
}
