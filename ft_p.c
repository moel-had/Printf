/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-had <moel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:23:12 by moel-had          #+#    #+#             */
/*   Updated: 2021/12/25 14:05:58 by moel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned long int num)
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

static void	ft_put_p(unsigned long int num)
{
	if (num >= 16)
	{
		ft_put_p(num / 16);
		ft_put_p(num % 16);
	}
	else if (num <= 9)
		ft_putchar(num + '0');
	else
		ft_putchar(num - 10 + 'a');
}

int	ft_print_p(unsigned long int num)
{
	int	len;

	len = 0;
	len += ft_printstr("0x");
	if (num == 0)
		len += ft_printchar('0');
	else
	{
		ft_put_p(num);
		len += ft_len(num);
	}
	return (len);
}
