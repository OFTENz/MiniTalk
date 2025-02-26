/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:32:02 by sel-mir           #+#    #+#             */
/*   Updated: 2025/02/26 20:17:50 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>

void	print_bits(unsigned char octet);
void	handler(int wht, siginfo_t *info, void *moreinfo);
void	zram(int wht, siginfo_t *info, void *moreinfo);
void	putstr(unsigned char *str);
void	emoji_handle(int wht, siginfo_t *info, void *moreinfo);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	general_act(int *a, unsigned char *buffer);
void	out(void);
void	bytes(int *a, unsigned char *buffer, siginfo_t *info);

int		ft_atoi(const char *str);
int		killa(pid_t pid, int sig);
int		check_bytes(unsigned char unit);

#endif
