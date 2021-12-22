/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-had <moel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:04:45 by moel-had          #+#    #+#             */
/*   Updated: 2021/12/22 18:52:24 by moel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

static int	ft_ulen(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static void	ft_putunbr(unsigned int nbr)
{
	if (nbr >= 10)
	{
		ft_putunbr(nbr / 10);
		ft_putunbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

int	ft_print_u(unsigned int nbr)
{
	int	len;

	len = ft_ulen(nbr);
	ft_putunbr(nbr);
	return (len);
}
