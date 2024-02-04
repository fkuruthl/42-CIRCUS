/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuruthl <fkuruthl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:49:38 by fkuruthl          #+#    #+#             */
/*   Updated: 2024/01/31 13:04:35 by fkuruthl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <limits.h>

int		ft_isdigit(int c);
int		error_check(int pid, char *str);
int		ft_atoi(const char *str);
void	send_message(char *str, int pid);
void	client_input(int signal);
void	ft_putnbr(int n);
void	ft_putchar(char c);

#endif

