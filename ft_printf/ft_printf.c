/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:02:35 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/21 11:57:05 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_is_listed(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_print_arg(const char cnt, va_list ap)
{
	int	counter;

	counter = 0;
	if (cnt == 'c')
		counter += ft_putchar((char)va_arg(ap, int));
	else if (cnt == 'd')
		counter += ft_putnbr(va_arg(ap, int));
	else if (cnt == 's')
		counter += ft_putstr(va_arg(ap, char *));
	else if (cnt == 'i')
		counter += ft_putnbr(va_arg(ap, int));
	else if (cnt == 'u')
		counter += ft_putunbr(va_arg(ap, unsigned int));
	else if (cnt == 'x' || cnt == 'X')
		counter += ft_puthexadecimal(va_arg(ap, unsigned int), cnt);
	else if (cnt == 'p')
		counter += ft_putpointer((unsigned long long)va_arg(ap, void *));
	else if (cnt == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *cnt, ...)
{
	va_list	ap;
	int		i;
	int		counter;

	i = 0;
	va_start(ap, cnt);
	counter = 0;
	while (cnt[i])
	{
		if (cnt[i] == '%' && ft_is_listed(cnt[i + 1]))
		{
			i++;
			counter += ft_print_arg(cnt[i], ap);
		}
		else
			counter += ft_putchar(cnt[i]);
		i++;
	}
	va_end(ap);
	return (counter);
}
/*
int	main(void)
{
	int x = 10;
	int	*ptr = &x;
	char s[] = "Hello: %d %c %s %p  %%\n";
	int	counter;
	counter = ft_printf(s, 1, 'A', "world", ptr);
	printf("Printed n: %d\n", counter);
	counter = printf("Hello: %d %c %s %p  %%\n", 1, 'A', "world", ptr);
	printf("Printed n: %d", counter);
	return (0);
}*/
