/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:37:53 by sel-mir           #+#    #+#             */
/*   Updated: 2025/02/26 18:07:39 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

static void	ft_putchar(int c, int fd)
{
	c += 48;
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n <= 9 && n >= 0)
		ft_putchar(n, fd);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			a;
	char			*p;

	p = (char *)s;
	a = 0;
	while (a < n)
	{
		p[a] = 0;
		a++;
	}
}

void	out(void)
{
	write (2, "\nFailed to Send the signal !\n", 28);
	exit(1);
}
