/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuruthl <fkuruthl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:49:24 by fkuruthl          #+#    #+#             */
/*   Updated: 2024/01/31 13:04:12 by fkuruthl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(char *str, int pid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		j = 7;
		while (j >= 0)
		{
			if ((c >> j) & 1)
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			usleep(300);
			j--;
		}
		i++;
	}
}

int	error_check(int pid, char *str)
{
	int	i;

	i = 0;
	if (pid <= 0)
	{
		write(1, "Error: PID is invalid\n", 23);
		return (0);
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1)
		{
			write(1, "Error: Alphabets are not allowed\n", 34);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		write(1, "Error: ./client PID message\n", 29);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (!error_check(pid, av[1]))
		return (1);
	send_message(av[2], pid);
	return (0);
}

