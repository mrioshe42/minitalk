/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <<mrios-he@student.42luxembourg.lu>#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:34:32 by mrios-he          #+#    #+#             */
/*   Updated: 2024/05/02 14:28:22 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

void	print_error(const char *msg);
void	send_signal(int pid, unsigned char c);
void	send_message(const char *message, int pid);
void	received(int sig);
void	print_banner(int pid);
void	msg_error(void);
void	send_signal_back(int signal, siginfo_t *info);
void	handle_signal(int signal, siginfo_t *info, void *context);

#endif
