/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:14:25 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/21 12:10:37 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n >= 10)
	{
		counter += ft_putunbr(n / 10);
		counter += ft_putunbr(n % 10);
	}
	else
	{
		counter += ft_putchar(n + '0');
	}
	return (counter);
}
