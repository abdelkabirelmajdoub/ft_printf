/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:31:04 by ael-majd          #+#    #+#             */
/*   Updated: 2024/11/30 15:32:58 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xlower(unsigned int n)
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

int	ft_xupper(unsigned int n)
{
	char	*hex;
	char	buffer[100];
	int		count;
	int		i;

	hex = "0123456789ABCDEF";
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
