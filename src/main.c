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

int		ps_parse_flags(t_env *env, int nb_args, char **args)
{
	int i;

	i = 1;
	while (i < nb_args && ft_strncmp("-", args[i], 1) == 0)
	{
		if (args[i][1] && ft_isdigit(args[i][1]) == 1)
			break ;
		if (ft_strcmp("-v", args[i]) == 0)
			env->flags |= FLAGS_V;
		if (ft_strcmp("-c", args[i]) == 0)
			env->flags |= FLAGS_C;
		++i;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	t_env	env;
	int		pos_args;

	if (argc > 1)
	{
		env.flags = 0;
		pos_args = ps_parse_flags(&env, argc, argv);

		if (env.flags & FLAGS_V)
			ft_putendl("Flag -v Active");
		if (env.flags & FLAGS_C)
			ft_putendl("Flag -c Active");

		ps_parse(argc - pos_args, &(argv[pos_args]));
	}
	else
		ft_error_str_exit("Need arguments.\n");
	return (0);
}
