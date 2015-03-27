/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 17:09:36 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/20 17:09:38 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_error_usage(void)
{
	ft_error_str_exit("usage: push_swap [-cvmn] [int_value ...]\n");
}

static void	ps_parse_flags_one_arg(t_env *env, char *str)
{
	if (ft_strchr(str, 'c') != NULL)
		env->flags |= FLAGS_C;
	if (ft_strchr(str, 'v') != NULL)
		env->flags |= FLAGS_V;
	if (ft_strchr(str, 'm') != NULL)
		env->flags |= FLAGS_M;
	if (ft_strchr(str, 'n') != NULL)
		env->flags |= FLAGS_N;
}

static int	ps_parse_flags(t_env *env, int nb_args, char **args)
{
	int i;

	i = 1;
	while (i < nb_args && ft_strncmp("-", args[i], 1) == 0)
	{
		if (args[i][1] && ft_isdigit(args[i][1]) == 1)
			break ;
		ps_parse_flags_one_arg(env, args[i]);
		++i;
	}
	return (i);
}

int			main(int argc, char **argv)
{
	t_env	env;
	int		pos_args;
	int		print;

	if (argc > 1)
	{
		print = 1;
		env.flags = 0;
		env.nb_ops = 0;
		env.stack_a = NULL;
		env.stack_b = NULL;
		pos_args = ps_parse_flags(&env, argc, argv);
		if (env.flags & FLAGS_M)
			print = 0;
		ps_parse(&env, argc - pos_args, &(argv[pos_args]));
	ps_print_stack(env.stack_a);
		ps_algo_sort(&env);

		ft_putendl("\nIs Sorted"), ft_putnbr(ps_stack_is_sorted(env.stack_a, 0));

		if (env.flags & FLAGS_N)
			ft_putendl("\nNumber of operations"), ft_putnbr(env.nb_ops);
		ft_putstr("\n");
	}
	else
		ps_error_usage();
	return (0);
}
