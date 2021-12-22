/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-had <moel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:26:07 by moel-had          #+#    #+#             */
/*   Updated: 2021/12/22 18:54:01 by moel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_x(va_arg(args, unsigned int), format);
	else if (format == 'p')
		len += ft_print_p(va_arg(args, unsigned long int));
	else if (format == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/*
int	main()
{
	char	c = 'a';
	char	*s = "Hello";
	int		i = 60;

	printf("%d\n", ft_printf("%c\n%s\n%d\n%x\n%u\n", c, s, i, i, i));
}
*/
/*
int	main()
{
	int	a = 0;
	ft_printf("%p\n", &a);
}
*/
