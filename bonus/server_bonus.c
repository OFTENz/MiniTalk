/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:32:45 by sel-mir           #+#    #+#             */
/*   Updated: 2025/02/26 21:14:33 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	emoji_handle(int wht, siginfo_t *info, void *moreinfo)
{
	static int				pid;
	static unsigned char	buffer[8];
	static int				trk;
	static int				a;

	(void)moreinfo;
	if (pid != (*info).si_pid)
	{
		ft_bzero(buffer, 8);
		pid = (*info).si_pid;
		trk = 0;
		a = 0;
	}
	if (wht == SIGUSR1)
		buffer[a] = buffer[a] * 2 | 0;
	else if (wht == SIGUSR2)
		buffer[a] = buffer[a] * 2 | 1;
	trk++;
	if (trk == 8)
	{
		bytes(&a, buffer, info);
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
	write (1, "\n", 1);
	ss.sa_sigaction = &emoji_handle;
	ss.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &ss, NULL);
	sigaction(SIGUSR2, &ss, NULL);
	while (1)
		pause();
}
