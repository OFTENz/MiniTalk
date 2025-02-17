#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <stdarg.h>

void	print_bits(unsigned char octet);
void	handler(int wht, siginfo_t *info, void *moreinfo);

int		ft_atoi(const char *str);
int		killa(pid_t pid, int sig);


#endif

