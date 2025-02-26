/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:30:58 by sel-mir           #+#    #+#             */
/*   Updated: 2025/02/26 20:14:18 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	ft_cmplt(int sign)
{
	if (sign == -1)
		return (0);
	return (-1);
}

void	putstr(unsigned char *str)
{
	int	a;

	a = 0;
	while (str[a])
		write (1, &str[a++], 1);
}

int	ft_atoi(const char *str)
{
	int			a;
	long long	res;
	int			sign;
	long long	d;

	sign = 1;
	res = 0;
	a = 0;
	while (str[a])
	{
		if (!(str[a] <= '9' && str[a] >= '0'))
			return (-1);
		a++;
	}
	a = 0;
	while (str[a] <= '9' && str[a] >= '0')
	{
		d = res;
		res = res * 10 + str[a++] - 48;
		if (res > INT_MAX)
			return (0);
		if (res / 10 != d)
			return (ft_cmplt(sign));
	}
	return (res * sign);
}

int	check_bytes(unsigned char unit)
{
	int	i;
	int	a;

	a = 0;
	i = 128;
	while (i > 0)
	{
		if (unit >= i)
		{
			a++;
			unit %= i;
		}
		else
			return (a);
		i /= 2;
	}
	return (a);
}

void	general_act(int *a, unsigned char *buffer)
{
	if (a)
		buffer[*a + 1] = 0;
	else
		buffer[1] = 0;
	putstr(buffer);
	*a = 0;
}
