/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:13:46 by mrios-he          #+#    #+#             */
/*   Updated: 2024/05/02 14:21:16 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

void	print_error(const char *msg);
void	send_signal(int pid, unsigned char c);
void	send_message(const char *message, int pid);
void	received(int sig);

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	server_pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		ft_printf("client pid: %d\n", getpid());
		signal(SIGUSR1, received);
		signal(SIGUSR2, received);
		send_message(argv[2], server_pid);
	}
	else
		print_error("Compile: ./client <server_pid> <text_to_sent>\n");
	return (0);
}

void	print_error(const char *msg)
{
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);
}

void	send_signal(int pid, unsigned char c)
{
	int				bit;
	unsigned char	temp;

	temp = c;
	bit = 8;
	while (bit > 0)
	{
		bit--;
		temp = c >> bit;
		if (temp % 2 == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				print_error("Error sending signal to server.\n");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				print_error("Error sending signal to server.\n");
		}
		usleep(100);
	}
}

void	send_message(const char *message, int pid)
{
	int	i;

	i = 0;
	while (message[i])
		send_signal(pid, message[i++]);
	send_signal(pid, '\0');
}

void	received(int sig)
{
	static int				bits;
	static unsigned char	current_char;
	static int				total_bytes;

	current_char |= (sig == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		if (current_char == '\0')
			ft_printf("Received back %d bytes!\n", total_bytes);
		bits = 0;
		current_char = 0;
		total_bytes++;
	}
	else
		current_char <<= 1;
}
