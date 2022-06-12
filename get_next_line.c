/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigo <mrodrigo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:55:14 by mrodrigo          #+#    #+#             */
/*   Updated: 2022/05/15 02:31:36 by mrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_get_line(int fd, char *str, int *value);
void	*ft_line(char *str, size_t len, int value);
void	*ft_next_line(char *str, size_t len, int value);

char	*get_next_line(int fd)
{
	size_t			len;
	int				value;
	char			*line;
	static char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_get_line(fd, str, &value);
	if (str == NULL)
		return (NULL);
	if (value != 0)
		len = ft_strlen(str, '\n');
	else
		len = ft_strlen(str, '\0');
	line = ft_line(str, len, value);
	str = ft_next_line(str, len, value);
	return (line);
}

void	*ft_get_line(int fd, char *str, int *value)
{
	char	*temp;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	*value = 1;
	while (*value != 0 && !ft_strchr(str, '\n'))
	{
		*value = read(fd, temp, BUFFER_SIZE);
		if (*value == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[*value] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

void	*ft_line(char *str, size_t len, int value)
{
	size_t	x;
	char	*line;

	x = 0;
	if (str[x] == '\0')
		return (NULL);
	if (value != 0)
		line = malloc((len + 2) * sizeof(char));
	else
		line = malloc((len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (str[x] != '\n' && str[x] != '\0')
	{
		line[x] = str[x];
		x++;
	}
	if (str[x] == '\n')
	{
		line[x] = str[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

void	*ft_next_line(char *str, size_t len, int value)
{
	size_t	x;
	char	*temp;

	x = ft_strlen(str, '\0');
	if (str[x] == '\0' && value == 0)
	{
		free(str);
		return (NULL);
	}
	temp = malloc((x - len + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	x = 0;
	len++;
	while (str[len] != '\0')
	{
		temp[x] = str[len];
		x++;
		len++;
	}
	temp[x] = '\0';
	free(str);
	return (temp);
}
