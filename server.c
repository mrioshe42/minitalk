/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:14:40 by mrios-he          #+#    #+#             */
/*   Updated: 2024/05/02 15:21:39 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context);
void	print_banner(int pid);

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

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bits;

	(void)context;
	(void)info;
	current_char |= (signal == SIGUSR1);
	bits++;
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
}
