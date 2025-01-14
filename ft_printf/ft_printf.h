/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:25:14 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/21 11:41:37 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_atoi(const char *str);
int	ft_putpointer(unsigned long long num);
int	ft_puthexadecimal(unsigned int num, int x);
int	ft_putunbr(unsigned int n);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_printf(const char *cnt, ...);

#endif
