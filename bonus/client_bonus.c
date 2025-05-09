/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:16:16 by sel-mir           #+#    #+#             */
/*   Updated: 2025/02/26 18:07:52 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

// this functin is the one that determine if she'll send te siguser1 or 2
// and she only receive one byte !

void	send_char(unsigned char unit, int pid)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (unit >= i)
		{
			if (kill(pid, SIGUSR2) < 0)
				out();
			unit %= i;
		}
		else
		{
			if (kill(pid, SIGUSR1) < 0)
				out();
		}
		usleep(600);
		usleep(600);
		i /= 2;
	}
}

static void	respond(int sig)
{
	if (sig == SIGUSR1)
	{
		write (1, "\nAcknowledgement Received !\n", 28);
		exit(1);
	}
}

// this functions send evry byte of the av[1] !

void	handle_it(int pid, char **av)
{
	int	a;

	a = 0;
	if (!av[1][0])
		return ;
	while (av[2][a])
	{
		send_char(av[2][a], pid);
		a++;
		usleep(100);
	}
	send_char(av[2][a], pid);
}

// This function checks if the string that contains pid 
// is valid or not byt seeing if it contains only numbers if so 
// send it to atoi wich handles the int max overflow !

int	pid_check(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (!(str[a] <= '9' && str[a] >= '0'))
			return (-1);
		a++;
	}
	return (ft_atoi(str));
}

int	main(int ac, char **av)
{
	int			pid;

	if (ac != 3 || (av[2] && !av[2][0]))
	{
		write (2, "Error !\nUsage : ./client_B <Pid>  <Message>\n", 44);
		return (1);
	}
	pid = pid_check(av[1]);
	if (pid <= 0)
	{
		write (2, "Invalid Pid !\n", 14);
		exit(-1);
	}
	signal(SIGUSR1, respond);
	handle_it(pid, av);
	while (1)
		pause();
}
