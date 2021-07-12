/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:14:13 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/12 13:56:57 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_send_char(int pid, unsigned char c)
{
	int	counter;

	counter = 7;
	while (counter >= 0)
	{
		if ((c >> counter) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(STDERR_FILENO, "Invalid pid.\n", 19);
				return (0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(STDERR_FILENO, "Invalid pid.\n", 19);
				return (0);
			}
		}
		counter--;
		usleep(50);
	}
	return (1);
}

static void	ft_message_received(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "Message received by server.\n", 28);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*msg;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		signal(SIGUSR1, ft_message_received);
		while (*msg)
		{
			if (!ft_send_char(pid, *msg))
				return (0);
			msg++;
		}
		ft_send_char(pid, *msg);
	}
	else
		write(STDERR_FILENO, "Usage: ./client <server-pid> <message>\n", 39);
	return (0);
}
