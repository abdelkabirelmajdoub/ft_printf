/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:48:10 by ael-majd          #+#    #+#             */
/*   Updated: 2024/12/01 12:52:18 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print(const char *format, va_list args, int i)
{
	int	j;

	j = 0;
	if (format[i] == 'c')
		j = ft_putchar(va_arg(args, int));
	else if (format[i] == 's')
		j = ft_putstr(va_arg(args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		j = ft_putnbr(va_arg(args, int));
	else if (format[i] == 'x')
		j = ft_xlower(va_arg(args, int));
	else if (format[i] == 'X')
		j = ft_xupper(va_arg(args, int));
	else if (format[i] == 'p')
		j = print_adress(va_arg(args, void *));
	else if (format[i] == 'u')
		j = print_u(va_arg(args, unsigned int));
	else if (format[i])
		j = write(1, &format[i], 1);
	return (j);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (write(1, 0, 0) < 0)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += print(format, args, ++i);
		else
			count += write(1, &format[i], 1);
		if (format[i])
			i++;
	}
	va_end(args);
	return (count);
}
