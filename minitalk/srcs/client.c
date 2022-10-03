/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eukwon <eukwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:08:18 by eukwon            #+#    #+#             */
/*   Updated: 2022/10/03 14:37:53 by eukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	send_bit(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 0;
		c = *str++;
		while (i < 8)
		{
			if (c << i & 128)
				kill(pid, SIGUSR2); // 1 보내기
			else
				kill(pid, SIGUSR1); // 0 보내기
			usleep(100);
			i++;
		}
	}
	return ;
	// while (i--)
	// {
	// 	kill(pid, SIGUSR1);
	// 	usleep(100);
	// }
}

static void	handler_sigusr(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3 || !ft_strlen(argv[2]))
		exit(0);
	ft_putstr_fd("Client PID: ", 1);
	ft_putstr_fd(ft_itoa(getpid()), 1);
	write(1, "\n", 1);

	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	send_bit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause(); // wait signal from server
}
