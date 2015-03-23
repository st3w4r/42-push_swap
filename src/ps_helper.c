/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 10:39:02 by ybarbier          #+#    #+#             */
/*   Updated: 2015/03/23 10:39:03 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr(stack->nbr);
		ft_putendl("");
		stack = stack->down;
	}
}
