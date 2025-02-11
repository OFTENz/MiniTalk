#include "../minitalk.h"

void	print_bits(unsigned char octet)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (octet >= i)
		{
			write (1, "1", 1);
			octet %= i;
		}
		else
			write (1, "0", 1);
		i /= 2;
	}
}

int	killa(pid_t pid, int sig)
{
	if (sig == SIGUSR1)
	{
		printf(", 0");
		fflush(stdout);
	}
	if (sig == SIGUSR2)
	{
		printf(", 1");
		fflush(stdout);
	}
	return(kill(pid, sig));
}

static int	ft_cmplt(int sign)
{
	if (sign == -1)
		return (0);
	return (-1);
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
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign *= -1;
		a++;
	}
	while (str[a] <= '9' && str[a] >= '0')
	{
		d = res;
		res = res * 10 + str[a++] - 48;
		if (res / 10 != d)
			return (ft_cmplt(sign));
	}
	return (res * sign);
}

