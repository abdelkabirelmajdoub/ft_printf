/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:53:54 by ael-majd          #+#    #+#             */
/*   Updated: 2024/11/30 15:33:56 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned long n)
{
	char	*hex;
	char	buffer[100];
	int		count;
	int		i;

	hex = "0123456789abcdef";
	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	count = 0;
	while (n)
	{
		buffer[i++] = hex[n % 16];
		count++;
		n /= 16;
	}
	while (i)
	{
		write(1, &buffer[i - 1], 1);
		i--;
	}
	return (count);
}

int	print_adress(void *p)
{
	unsigned long	address;
	int				count;

	count = 0;
	address = (unsigned long)p;
	count += write(1, "0x", 2);
	count += ft_hexa(address);
	return (count);
}
