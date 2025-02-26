/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hlp_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:14:44 by sel-mir           #+#    #+#             */
/*   Updated: 2025/02/26 20:17:14 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	bytes(int *a, unsigned char *buffer, siginfo_t *info)
{
	if (!buffer[0])
		kill((*info).si_pid, SIGUSR1);
	else if (check_bytes(buffer[0]) == 0)
		general_act(a, buffer);
	else if (check_bytes(buffer[0]) == 2 && *a == 1)
		general_act(a, buffer);
	else if (check_bytes(buffer[0]) == 3 && *a == 2)
		general_act(a, buffer);
	else if (check_bytes(buffer[0]) == 4 && *a == 3)
		general_act(a, buffer);
	else
		(*a)++;
}
