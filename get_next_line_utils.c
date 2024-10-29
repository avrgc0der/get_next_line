/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:45:58 by enoshahi          #+#    #+#             */
/*   Updated: 2024/10/29 13:44:32 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
USED FUNCTS:
- strjoin
- strdup
- calloc
- strlen
- strchr
*/

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!tmp)
		return (NULL);
	while (s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		tmp[j + i] = s2[j];
		j++;
	}
	tmp[j + i] = '\0';
	return (tmp);
}

char	*ft_strdup(const char *str)
{
	int		len;
	char	*tmp;
	int		i;

	len = 0;
	i = 0;
	while (str[len] != '\0')
		len++;
	tmp = ft_calloc(sizeof(char) * (len + 1));
	while (str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}


size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	curr;

	i = 0;
	curr = c;
	while (s[i] != '\0')
	{
		if (s[i] == curr)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == curr)
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}

