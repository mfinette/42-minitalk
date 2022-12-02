/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:54:33 by mfinette          #+#    #+#             */
/*   Updated: 2022/12/01 20:18:04 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(int argc, char *argv[])
{
	struct s_message	message;

	if (!parse_args(&message, argc, argv))
	{
		ft_putendl_fd("argument error", 2);
		return (1);
	}
	send_message(&message);
	return (0);
}
