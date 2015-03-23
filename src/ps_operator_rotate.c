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

	if (!(env->stack_a) || !(env->stack_a->down))
		return ;
	elem_tmp = ps_stack_peek(&(env->stack_a)); // Save ptr a;
	elem_tmp_2 = ps_stack_peek(&(env->stack_a)); // Save ptr a move vers b;
	if (elem_tmp->down->down)
	{
		while (elem_tmp_2->down->down) // Recuperer l'avant dernier (b)
			elem_tmp_2 = elem_tmp_2->down;
		env->stack_a = elem_tmp_2->down; //Mettre le TOP sur c
		elem_tmp_2->down->down = elem_tmp->down; // Mettre down de c avec la valeur down de a
		elem_tmp_2->down = elem_tmp; //Mettre down de b avec ptr sur a
	}
	else
		ps_stack_swap_top(&(env->stack_a));
	elem_tmp->down = NULL; //Mettre down de a sur  NULL
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

	if (!(env->stack_b) || !(env->stack_b->down))
		return ;
	elem_tmp = ps_stack_peek(&(env->stack_b)); // Save ptr a;
	elem_tmp_2 = ps_stack_peek(&(env->stack_b)); // Save ptr a move vers b;
	if (elem_tmp->down->down)
	{
		while (elem_tmp_2->down->down) // Recuperer l'avant dernier (b)
			elem_tmp_2 = elem_tmp_2->down;
		env->stack_b = elem_tmp_2->down; //Mettre le TOP sur c
		elem_tmp_2->down->down = elem_tmp->down; // Mettre down de c avec la valeur down de a
		elem_tmp_2->down = elem_tmp; //Mettre down de b avec ptr sur a
	}
	else
		ps_stack_swap_top(&(env->stack_b));
	elem_tmp->down = NULL; //Mettre down de a sur  NULL
	if (is_print)
		ft_putendl("rb");
}

/*
** Name: rr
** Desc: ra et rb en meme temps.
** (vers le haut, le premier élément devient le dernier).
*/
void	ps_operator_rr(t_env *env, int is_print)
{
	ps_operator_ra(env, 0);
	ps_operator_rb(env, 0);
	if (is_print)
		ft_putendl("rr");
}
