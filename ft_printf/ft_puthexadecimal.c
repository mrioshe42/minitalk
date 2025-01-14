/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:31:20 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/21 12:09:39 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthexadecimal(unsigned int num, int x)
{
	int	counter;

	counter = 0;
	if (num >= 16)
	{
		counter += ft_puthexadecimal(num / 16, x);
		counter += ft_puthexadecimal(num % 16, x);
	}
	else if (num >= 10)
	{
		if (x == 'x')
			counter += ft_putchar(num - 10 + 49 + '0');
		else
			counter += ft_putchar(num - 10 + 17 + '0');
	}
	else
		counter += ft_putchar(num + '0');
	return (counter);
}
