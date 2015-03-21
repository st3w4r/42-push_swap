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
/*
char	ps_parse_add_to_stack(int nbr)
{

}
*/
void	ps_parse(int nb_args, char **args)
{
	int		i;
	long	nbr_parse;


	i = 0;
	while (i < nb_args)
	{
	ft_putendl(args[i]);
		nbr_parse = ft_atol(args[i]);
		// ft_putnbr(nbr_parse);
			// ft_error_str_exit("Number only.");
		if (nbr_parse > 2147483647 || nbr_parse < -2147483648)
			ft_error_str_exit("Just Int value supported.\n");
		// ps_parse_add_to_stack((int)nbr_parse);
		++i;
	}
}
