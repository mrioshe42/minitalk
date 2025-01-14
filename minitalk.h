/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:42:27 by mrios-he          #+#    #+#             */
/*   Updated: 2024/05/02 15:20:59 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

void	print_error(const char *msg);
void	send_signal(int pid, unsigned char c);
void	send_message(const char *message, int pid);
void	handle_signal(int signal, siginfo_t *info, void *context);
void	print_banner(int pid);

#endif
