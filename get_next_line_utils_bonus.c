/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigo <mrodrigo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 02:40:32 by mrodrigo          #+#    #+#             */
/*   Updated: 2022/05/15 02:45:46 by mrodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str, char c)
{
	size_t	x;

	x = 0;
	if (str == NULL)
		return (0);
	while (str[x] != c)
		x++;
	return (x);
}

char	*ft_strchr(const char *str, int c)
{
	int	x;

	x = 0;
	if (str == NULL)
		return (NULL);
	while (str[x] != (unsigned char)c && str[x] != '\0')
		x++;
	if (str[x] == (unsigned char)c)
		return ((char *)&str[x]);
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			x;
	unsigned char	*str;
	unsigned char	*temp;

	x = 0;
	str = (unsigned char *)src;
	temp = (unsigned char *)dest;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (str < temp)
	{
		while (n > x)
		{
			n--;
			temp[n] = str[n];
		}
		return (temp);
	}
	while (n > x)
	{
		temp[x] = str[x];
		x++;
	}
	return (temp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		x;
	char	*temp;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	x = ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1;
	temp = malloc(x);
	if (temp == NULL)
		return (NULL);
	else
	{
		ft_memmove(temp, s1, ft_strlen(s1, '\0'));
		ft_memmove(temp + ft_strlen(s1, '\0'), s2, ft_strlen(s2, '\0'));
		temp[--x] = '\0';
	}
	free(s1);
	return (temp);
}
