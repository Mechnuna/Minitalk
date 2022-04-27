/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:55:15 by sstyx             #+#    #+#             */
/*   Updated: 2021/10/12 22:55:06 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>

# define FALSE 0
# define TRUE 1
# define BUFFER_SIZE 1024

typedef struct s_stack
{
	char		message[1024];
	int			top_bit;
	int			top_byte;
	_Bool		all_receive;
	_Bool		buff_overflow;
}				t_stack;

void	ft_putstr(char *str);
void	error(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	my_handler(int signum, siginfo_t *siginfo, void *unused);
#endif