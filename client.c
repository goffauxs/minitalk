/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:14:13 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/09 15:38:46 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_char(int pid, unsigned char c)
{
	int	counter;

	counter = 7;
	while (counter >= 0)
	{
		if ((c >> counter) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		counter--;
		usleep(50);
	}
}

// void ft_acknowledged(int sig)
// {
// 	(void)sig;
// 	write(STDOUT_FILENO, "Message received by server.\n", 28);
// }

int main(int argc, char *argv[])
{
	int		pid;
	char	*msg;
	
	// signal(SIGUSR1, ft_acknowledged);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		while (*msg)
		{
			ft_send_char(pid, *msg);
			msg++;
		}
		ft_send_char(pid, *msg);
	}
	else
		write(STDOUT_FILENO, "Usage: ./client <server-pid> <message>\n", 39);
}