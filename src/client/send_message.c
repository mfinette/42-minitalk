/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:46:05 by mfinette          #+#    #+#             */
/*   Updated: 2022/12/02 07:52:36 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	send_char(int pid, char c)
{
	int	index;
	int	binary_c;

	index = 0;
	binary_c = dec_to_bin(c);
	while (index < 8)
	{
		if (get_index(binary_c, index))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		index++;
	}
}

void	send_message(struct s_message *message)
{
	size_t	i;

	i = 0;
	while (message->str[i])
	{
		send_char(message->pid, message->str[i]);
		i++;
	}
}
