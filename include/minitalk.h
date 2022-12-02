/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:09:19 by mfinette          #+#    #+#             */
/*   Updated: 2022/12/02 07:53:47 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

// *****CLIENT******

struct		s_message
{
	int		pid;
	char	*str;
};

int			parse_args(struct s_message *args, int argc, char *argv[]);
void		send_message(struct s_message *args);

// *****UTILS*****

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(const char *s, int fd);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);
int			ft_isdigit(int c);
void		ft_bzero(void *s, size_t n);
long		dec_to_bin(long n);
int			get_index(int nb, int index);

// *****SERVER*****

struct		s_character
{
	char	character;
	int		current_bit;
};

void		display_pid(void);

#endif