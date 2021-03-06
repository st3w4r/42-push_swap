/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 18:20:56 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/20 18:20:58 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long		ps_atol_nbr(const char *str, long result, long negatif)
{
	if (str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
			|| *str == '\f' || *str == '\v')
			str++;
		if (*str == '-')
		{
			negatif = 1;
			str++;
		}
		else if (*str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			result += *str++ - '0';
			if (*str >= '0' && *str <= '9')
				result *= 10;
		}
		if (*str && ft_isdigit(*str) == 0)
			ft_error_str_exit("Error\n");
	}
	return (negatif ? -result : result);
}

static int		ps_parse_check_number_duplicate(t_stack *stack, int nbr)
{
	while (stack)
	{
		if (nbr == stack->nbr)
		{
			return (1);
		}
		stack = stack->down;
	}
	return (0);
}

static void		ps_parse_add_to_stack(t_env *env, int nbr)
{
	t_stack *elem;

	elem = NULL;
	elem = (t_stack*)(malloc(sizeof(t_stack)));
	elem->nbr = nbr;
	ps_stack_push(&(env->stack_a), elem);
}

void			ps_parse(t_env *env, int nb_args, char **args)
{
	long	nbr_parse;

	nb_args -= 1;
	while (nb_args >= 0)
	{
		nbr_parse = ps_atol_nbr(args[nb_args], 0, 0);
		if (nbr_parse > 2147483647 || nbr_parse < -2147483648)
			ft_error_str_exit("Error\n");
		if (ps_parse_check_number_duplicate(env->stack_a, (int)nbr_parse) == 1)
			ft_error_str_exit("Error\n");
		ps_parse_add_to_stack(env, (int)nbr_parse);
		--nb_args;
	}
}
