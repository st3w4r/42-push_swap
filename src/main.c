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
	ft_error_str_exit("usage: push_swap [-cvm] [int_value ...]\n");
}

static void	ps_parse_flags_one_arg(t_env *env, char *str)
{
	if (ft_strchr(str, 'c') != NULL)
		env->flags |= FLAGS_C;
	if (ft_strchr(str, 'v') != NULL)
		env->flags |= FLAGS_V;
	if (ft_strchr(str, 'm') != NULL)
		env->flags |= FLAGS_M;
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
		env.stack_a = NULL;
		env.stack_b = NULL;

		pos_args = ps_parse_flags(&env, argc, argv);

		if (env.flags & FLAGS_V)
			ft_putendl("Flag -v Active");
		if (env.flags & FLAGS_C)
			ft_putendl("Flag -c Active");
		if (env.flags & FLAGS_M)
			print = 0;

		ps_parse(&env, argc - pos_args, &(argv[pos_args]));

		// ps_operator_ss(&env, print);
		// ps_operator_sa(&env, print);

		ft_putendl("Is Sorted");
		ft_putnbr(ps_stack_is_sorted(env.stack_a));
		ft_putendl("");

ft_putendl("Stack a");
		ps_print_stack(env.stack_a);
ft_putendl("Stack b");
		ps_print_stack(env.stack_b);

ft_putendl("");



ps_operator_sa(&env, print);
ps_operator_pb(&env, print);
ps_operator_pb(&env, print);
ps_operator_pb(&env, print);
ps_operator_sa(&env, print);
ps_operator_pa(&env, print);
ps_operator_pa(&env, print);
ps_operator_pa(&env, print);


// ps_operator_ra(&env, print);
// ps_operator_pb(&env, print);
// ps_operator_pb(&env, print);
// ps_operator_pb(&env, print);
// ps_operator_pb(&env, print);

// ps_operator_ra(&env, print);
// ps_operator_rrb(&env, print);
// env.stack_b = NULL;
/*ps_operator_pa(&env, print);
ps_operator_pb(&env, print);
ps_operator_sa(&env, print);
ps_operator_sb(&env, print);
ps_operator_ss(&env, print);
ps_operator_ra(&env, print);
ps_operator_rb(&env, print);
ps_operator_rr(&env, print);
ps_operator_rra(&env, print);
ps_operator_rrb(&env, print);
ps_operator_rrr(&env, print);*/
// ps_operator_pa(&env, print);
// ps_operator_rra(&env, print);
// ps_operator_rrr(&env, print);

// ps_operator_pa(&env, print);
// ps_stack_pop(&(env->stack_a))
ft_putendl("");

ft_putendl("Stack a");
		ps_print_stack(env.stack_a);
ft_putendl("Stack b");
		ps_print_stack(env.stack_b);

		ft_putendl("Is Sorted");
		ft_putnbr(ps_stack_is_sorted(env.stack_a));
		ft_putendl("");


	}
	else
		ps_error_usage();
	return (0);
}
