/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuruthl <fkuruthl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:02:02 by fkuruthl          #+#    #+#             */
/*   Updated: 2024/01/17 17:10:00 by fkuruthl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_fd(int fd, char *pent_buffer)
{
	char	*temp_buff;
	int		len;

	temp_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buff)
		return (NULL);
	len = 1;
	while (!ft_strchr(pent_buffer, '\n') && (len != 0))
	{
		len = read(fd, temp_buff, BUFFER_SIZE);
		if (len < 0)
		{
			free(temp_buff);
			free(pent_buffer);
			return (NULL);
		}
		temp_buff[len] = '\0';
		pent_buffer = ft_strjoin(pent_buffer, temp_buff);
	}
	free(temp_buff);
	return (pent_buffer);
}

char	*skip_duplicate(char *pent_buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (pent_buffer[i] != '\0' && pent_buffer[i] != '\n')
		i++;
	if (pent_buffer[i] == '\0')
	{
		free(pent_buffer);
		return (NULL);
	}
	new_buffer = malloc(ft_strlen(pent_buffer) - i + 1);
	if (!new_buffer)
		return (NULL);
	i++;
	j = 0;
	while (pent_buffer[i] != '\0')
		new_buffer[j++] = pent_buffer[i++];
	new_buffer[j] = '\0';
	free(pent_buffer);
	return (new_buffer);
}

char	*ft_line(char *str)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!*str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	new_line = (char *)malloc((i + 2));
	if (!new_line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		new_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new_line[i] = str[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*pent_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	pent_buffer = read_from_fd(fd, pent_buffer);
	if (!pent_buffer)
	{
		return (NULL);
	}
	line = ft_line(pent_buffer);
	pent_buffer = skip_duplicate(pent_buffer);
	return (line);
}