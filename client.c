/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:16:16 by sel-mir           #+#    #+#             */
/*   Updated: 2025/02/09 16:57:59 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

// this functin is the one that determine if she'll send te siguser1 or 2
// and she only receive one byte !

int	send_char(unsigned char unit, int pid)
{
	int	i;
	
	i = 128;
	if (!unit)
		return (write (2, "Empty String !\n", 15));
	while (i > 0)
	{
		if (unit >= i)
		{
			if (kill(pid, siguser1) < 0)
			{
				write (1, "Failed to Send the signal !\n", 28);
				return (-1);
			}
			unit %= i;
		}
		else
			kill(pid, siguser2);
		usleep(600);
		i /= 2;
	}

}

// This function checks if the string that contains pid 
// is valid or not byt seeing if it contains only numbers if so 
// send it to atoi wich handles the int max overflow !

int	pid_check(char *str)
{
	int	a;

	a  = 0;
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
	char *message;
	int	pid;

if (ac != 3)
{
	write (2, "Error !\n", 8);
	return (-1);
}

	pid = pid_check(av[1]);
	if (pid == -1)
		return (write (2, "Invalid Pid !\n", 14));
	

}