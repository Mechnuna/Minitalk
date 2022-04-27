/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyx <sstyx@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:25:56 by sstyx             #+#    #+#             */
/*   Updated: 2021/10/12 20:00:21 by sstyx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decimal_conversion(char c, int power, int pid)
{
	uint8_t		ascii;

	ascii = c;
	if (power > 0)
		decimal_conversion(ascii / 2, power - 1, pid);
	if ((ascii % 2) == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr("Error signal!\n");
			exit(0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr("Error signal!\n");
			exit(0);
		}
	}
	usleep(1000);
}

int	send_message(int server_pid, char *msg)
{
	int		i;

	i = 0;
	if (!(msg))
		ft_putstr("Empty line\n");
	while (msg[i] != '\0')
	{
		decimal_conversion(msg[i], 7, server_pid);
		i++;
	}
	exit (0);
	return (0);
}

void	my_handler(int signum, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)siginfo;
	(void)signum;
	ft_putstr("\033[1;32mSignal received\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	catch;

	catch.sa_flags = SA_SIGINFO;
	catch.sa_sigaction = my_handler;
	if ((sigaction(SIGUSR2, &catch, 0)) == -1)
		error("Error sigaction\n");
	if (argc == 3)
		send_message(atoi(argv[1]), argv[2]);
	else
		error("\033[1;31mError arguments\n");
	while (1)
		pause();
	return (0);
}
