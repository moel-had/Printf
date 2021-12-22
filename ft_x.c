/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-had <moel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:07:34 by moel-had          #+#    #+#             */
/*   Updated: 2021/12/22 18:58:11 by moel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

static int	ft_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_x(unsigned int num, char format)
{
	if (num >= 16)
	{
		ft_put_x(num / 16, format);
		ft_put_x(num % 16, format);
	}
	else if (num <= 9)
		ft_putchar(num + '0');
	else
	{
		if (format == 'x')
			ft_putchar(num - 10 + 'a');
		if (format == 'X')
			ft_putchar(num - 10 + 'A');
	}
}

int	ft_print_x(unsigned int num, char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_x(num, format);
	return (ft_len(num));
}
