/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:14:40 by mrios-he          #+#    #+#             */
/*   Updated: 2024/05/02 17:22:20 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

void	print_banner(int pid);
void	msg_error(void);
void	send_signal_back(int signal, siginfo_t *info);
void	handle_signal(int signal, siginfo_t *info, void *context);

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	print_banner(getpid());
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}

void	print_banner(int pid)
{
	ft_printf("██ ██ █ ██  █ █ █████ ████ █   █  █\n");
	ft_printf("█ █ █ █ █ █ █ █   █   █  █ █   █ █ \n");
	ft_printf("█   █ █ █  ██ █   █   ████ █   ███ \n");
	ft_printf("█   █ █ █   █ █   █   █  █ ███ █  █\n");
	ft_printf("        Server PID: %d             \n", pid);
}

void	msg_error(void)
{
	ft_printf("server : unexpected error\n");
	exit(EXIT_FAILURE);
}

void	send_signal_back(int signal, siginfo_t *info)
{
	if (signal == SIGUSR1)
	{
		if (kill(info->si_pid, SIGUSR1) == -1)
			msg_error();
	}
	else if (signal == SIGUSR2)
	{
		if (kill(info->si_pid, SIGUSR2) == -1)
			msg_error();
	}
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bits;
	static pid_t			last_client_pid;

	(void)context;
	current_char |= (signal == SIGUSR1);
	bits++;
	if (info->si_pid != last_client_pid)
	{
		ft_printf("Received signal from PID: %d\n", info->si_pid);
		last_client_pid = info->si_pid;
	}
	if (bits == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		bits = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
	send_signal_back(signal, info);
}
