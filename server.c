#include "minitalk.h"

void	handler(int wht, siginfo_t *info, void *moreinfo)
{
	static int	pid;
	static	unsigned char	buffer;
	static int	trk;

	(void)moreinfo;

	if (pid != (*info).si_pid)
	{
		buffer = 0;
		pid = (*info).si_pid;
		trk = 0;
	}

	if (wht == SIGUSR1)
	{
		// printf("\n\n SIGUSR1");
		buffer = buffer * 2 | 0;
	}

	else if (wht == SIGUSR2)
	{
		// printf("\n\n SIGUSR2");
		buffer = buffer * 2 | 1;
	}

	trk++;
	if (trk == 8 && buffer)
	{
		if (!buffer)
		{
			printf("\n\n [+] Server : End of the String !");
			fflush(stdout);
			exit(0);
		}
		write (1, &buffer, 1);
		fflush(stdout);

		// print_bits(buffer);
		// fflush(stdout);

		// printf("\n\n");
		// fflush(stdout);

		buffer = '\0';
		trk = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("\n\n The pid is : %d", pid);
	fflush(stdout);
	struct sigaction	ss;
	ss.sa_sigaction = &handler;
	ss.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &ss, NULL);
	sigaction(SIGUSR2, &ss, NULL);
	while (1)
		pause();
}