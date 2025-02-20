#include "minitalk_bonus.h"

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

	if (wht == SIGUSR1 )
		buffer = buffer * 2 | 0;
	else if (wht == SIGUSR2)
		buffer = buffer * 2 | 1;
	trk++;
	if (trk == 8)
	{
		write (1, &buffer, 1);
		fflush(stdout);
		buffer = '\0';
		trk = 0;
	}
}

int	main(void)
{
	struct sigaction	ss;
	int			pid;

	pid = getpid();
	if (!pid)
		return(1);
	printf("\n\n The pid is : %d", pid);
	fflush(stdout);
	ss.sa_sigaction = &handler;
	ss.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &ss, NULL);
	sigaction(SIGUSR2, &ss, NULL);
	while (1)
		pause(); 
}