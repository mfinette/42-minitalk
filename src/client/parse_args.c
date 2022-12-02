/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:55:42 by mfinette          #+#    #+#             */
/*   Updated: 2022/12/02 07:36:08 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	is_int(const char *str)
{
	size_t	i;
	int		tmp;

	tmp = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			tmp = 1;
		else
			return (0);
		i++;
	}
	return (tmp);
}

int	parse_args(struct s_message *message, int argc, char *argv[])
{
	if (!message || argc != 3 || !is_int(argv[1]))
		return (0);
	message->pid = ft_atoi(argv[1]);
	message->str = argv[2];
	return (1);
}
