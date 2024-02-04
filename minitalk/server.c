/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuruthl <fkuruthl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:49:54 by fkuruthl          #+#    #+#             */
/*   Updated: 2024/01/31 12:22:42 by fkuruthl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_input(int signal)
{
	static int	bit;
	static char	current_char;

	if (signal == SIGUSR1)
	{
		current_char = (current_char << 1) | 1;
	}
	else if (signal == SIGUSR2)
	{
		current_char = (current_char << 1) | 0;
	}
	bit++;
	if (bit == 8)
	{
		write (1, &current_char, 1);
		bit = 0;
		current_char = 0;
	}
}

int	main(void)
{
	write(1, "HEYY!!\nThe pid is :", 20);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, client_input);
	signal(SIGUSR2, client_input);
	while (1)
	{
		pause();
	}
	return (0);
}

