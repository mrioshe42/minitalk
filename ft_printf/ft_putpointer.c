/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:46:12 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/21 12:09:59 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptr(unsigned long long num)
{
	int	counter;

	counter = 0;
	if (num >= 16)
	{
		counter += ft_putptr(num / 16);
		counter += ft_putptr(num % 16);
	}
	else if (num >= 10)
	{
		counter += ft_putchar(num - 10 + 'a');
	}
	else
		counter += ft_putchar(num + '0');
	return (counter);
}

int	ft_putpointer(unsigned long long num)
{
	int	counter;

	counter = 0;
	if (!num)
	{
		counter += ft_putstr("(nil)");
		return (counter);
	}
	if (num)
	{
		counter += ft_putstr("0x");
		counter += ft_putptr(num);
	}
	return (counter);
}
