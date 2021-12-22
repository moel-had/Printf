/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-had <moel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:57:09 by moel-had          #+#    #+#             */
/*   Updated: 2021/12/22 18:55:18 by moel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_print_u(unsigned int nbr);
int		ft_print_x(unsigned int num, char format);
int		ft_print_p(unsigned int long num);
int		ft_printf(const char *str, ...);
#endif
