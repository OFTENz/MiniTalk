/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:32:02 by sel-mir           #+#    #+#             */
/*   Updated: 2025/02/20 21:32:02 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
