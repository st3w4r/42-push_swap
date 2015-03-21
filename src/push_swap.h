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

#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdlib.h>

# define FREE(x) { if (x) free(x); x = NULL; }
# define FREE_ARR(x) { if (x && *x) ft_arrfree(&x); }

enum e_flags
{
	FLAGS_V = 1 << 0,
	FLAGS_C = 1 << 1
};

typedef struct s_nbr
{
	int				nbr;
	struct s_nbr	*next;
}					t_nbr;

typedef struct s_stack
{
	t_nbr	*top;
}				t_stack;

typedef struct s_env
{
	int		flags;
	t_stack stack_a;
	t_stack stack_b;
}				t_env;

/*
** Name: ps_parse
** File: ps_parse.c
** Desc: All functions parsing args
*/
void	ps_parse(int nb_args, char **argv);

/*
** Name: ft_error
** File: ft_error.c
** Desc: Error Gestion
*/
void	ft_exit(void);
void	ft_malloc_error(void);
void	ft_error_str(char *str);
void	ft_error_str_exit(char *str);

#endif
