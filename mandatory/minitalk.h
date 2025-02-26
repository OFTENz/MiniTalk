/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:33:16 by sel-mir           #+#    #+#             */
/*   Updated: 2025/02/26 18:43:13 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>

void	print_bits(unsigned char octet);
void	handler(int wht, siginfo_t *info, void *moreinfo);
void	ft_putnbr_fd(int n, int fd);
void	out(void);

int		ft_atoi(const char *str);
int		killa(pid_t pid, int sig);
void	putstr(unsigned char *str);
char	*clone(char *str);
int		ft_strlen(char *str);
int		check_bytes(unsigned char unit);

#endif
