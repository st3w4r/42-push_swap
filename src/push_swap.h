/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 17:10:52 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/20 17:10:54 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define FREE(x) { if (x) free(x); x = NULL; }
# define FREE_ARR(x) { if (x && *x) ft_arrfree(&x); }

enum	e_flags
{
	FLAGS_V = 1 << 0,
	FLAGS_C = 1 << 1,
	FLAGS_M = 1 << 2
};

typedef struct		s_stack
{
	int				nbr;
	struct s_stack	*down;
}					t_stack;

typedef struct		s_env
{
	int		flags;
	int		nb_ops;
	t_stack *stack_a;
	t_stack *stack_b;
}					t_env;

/*
** Name: ps_parse
** File: ps_parse.c
** Desc: All functions parsing args
*/
void				ps_parse(t_env *env, int nb_args, char **argv);

/*
** Name: ps_operator_swap
** File: ps_operator_swap.c
** Desc: All functions to swap elem on stack
** swap a - intervertit les 2 premiers éléments au sommet de la pile a.
** (ne fait rien s’il n’y en a qu’un ou aucun).
*/
void		ps_operator_sa(t_env *env, int is_print);
void		ps_operator_sb(t_env *env, int is_print);
void		ps_operator_ss(t_env *env, int is_print);

/*
** Name: ps_operator_push
** File: ps_operator_push.c
** Desc: All functions to push elem on stack
** push b - prend le premier élément au sommet de a et le met sur b.
** (ne fait rien si b est vide).
*/
void		ps_operator_pa(t_env *env, int is_print);
void		ps_operator_pb(t_env *env, int is_print);

/*
** Name: ps_operator_rotate
** File: ps_operator_rotate.c
** Desc: All functions to rotate stack UP
** rotate a - décale d’une position tous les élements de la pile a.
** (vers le haut, le premier élément devient le dernier).
*/
void		ps_operator_ra(t_env *env, int is_print);
void		ps_operator_rb(t_env *env, int is_print);
void		ps_operator_rr(t_env *env, int is_print);

/*
** Name: ps_operator_reverse
** File: ps_operator_reverse.c
** Desc: All functions to rotate stack DOWN
** reverse rotate a - décale d’une position tous les élements de la pile a.
** (vers le bas, le dernier élément devient le premier)..
*/
void		ps_operator_rra(t_env *env, int is_print);
void		ps_operator_rrb(t_env *env, int is_print);
void		ps_operator_rrr(t_env *env, int is_print);

/*
** Name: ps_algo
** File: ps_algo.c
** Desc: Algortihme to sort stack
*/
void		ps_algo_sort(t_env *env);

/*
** Name: ps_helper
** File: ps_helper.c
** Desc: Functions simply program
*/
void		ps_print_stack(t_stack *stack);
void		ps_print_operation(t_env *env, char *str);
int			ps_cmp_int(int nb1, int nb2);
int			ps_stack_is_sorted(t_stack *stack);

/*
** Name: ps_stack
** File: ps_stack.c
** Desc: Base operator of stack
*/
void		ps_stack_push(t_stack **stack, t_stack *elem);
t_stack		*ps_stack_pop(t_stack **stack);
int			ps_stack_empty(t_stack **stack);
int			ps_stack_size(t_stack *stack);
t_stack		*ps_stack_peek(t_stack **stack);
void		ps_stack_swap_top(t_stack **stack);


/*
** Name: ft_error
** File: ft_error.c
** Desc: Error Gestion
*/
void				ft_exit(void);
void				ft_malloc_error(void);
void				ft_error_str(char *str);
void				ft_error_str_exit(char *str);

#endif
