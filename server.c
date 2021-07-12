/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:14:21 by sgoffaux          #+#    #+#             */
/*   Updated: 2021/07/12 12:11:25 by sgoffaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

t_message	g_message;

static void	ft_print_pid(void)
{
	char	*pid;

	pid = ft_itoa((int)getpid());
	ft_putstr_fd("pid: ", STDOUT_FILENO);
	ft_putendl_fd(pid, STDOUT_FILENO);
}

static void	low_bit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	g_message.tmp_char <<= 1;
	g_message.counter++;
	if (g_message.counter % 8 == 0 && g_message.counter != 0)
	{
		if (g_message.tmp_char == '\0')
			kill(info->si_pid, SIGUSR1);
		else
			write(STDOUT_FILENO, &g_message.tmp_char, 1);
		g_message.tmp_char = 0;
	}
}

static void	high_bit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	g_message.counter++;
	g_message.tmp_char <<= 1;
	g_message.tmp_char |= 1;
	if (g_message.counter % 8 == 0)
	{
		write(STDOUT_FILENO, &g_message.tmp_char, 1);
		g_message.tmp_char = 0;
	}
}

int	main(void)
{
	struct sigaction	high;
	struct sigaction	low;
	int					ret;

	high.sa_sigaction = high_bit;
	low.sa_sigaction = low_bit;
	high.sa_flags = SA_SIGINFO;
	low.sa_flags = SA_SIGINFO;
	ret = sigaction(SIGUSR1, &high, NULL);
	if (ret != 0)
		write(STDERR_FILENO, "signal error\n", 13);
	ret = sigaction(SIGUSR2, &low, NULL);
	if (ret != 0)
		write(STDERR_FILENO, "signal error\n", 13);
	g_message.counter = 0;
	g_message.tmp_char = 0;
	ft_print_pid();
	while (1)
	{
	}
}
