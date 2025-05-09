/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:33:59 by sel-mir           #+#    #+#             */
/*   Updated: 2025/02/26 21:07:55 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int wht, siginfo_t *info, void *moreinfo)
{
	static int				pid;
	static unsigned char	buffer;
	static int				trk;

	(void)moreinfo;
	if (pid != (*info).si_pid)
	{
		buffer = 0;
		pid = (*info).si_pid;
		trk = 0;
	}
	if (wht == SIGUSR1)
		buffer = buffer * 2 | 0;
	else if (wht == SIGUSR2)
		buffer = buffer * 2 | 1;
	trk++;
	if (trk == 8)
	{
		write (1, &buffer, 1);
		buffer = '\0';
		trk = 0;
	}
}

int	main(void)
{
	struct sigaction	ss;
	int					pid;

	pid = getpid();
	if (!pid)
		return (1);
	write(1, "\n\n The pid is ", 14);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	ss.sa_sigaction = &handler;
	ss.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &ss, NULL);
	sigaction(SIGUSR2, &ss, NULL);
	while (1)
		pause();
}
