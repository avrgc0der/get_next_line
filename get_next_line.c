/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:46:15 by enoshahi          #+#    #+#             */
/*   Updated: 2024/10/28 18:51:23 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_new_line(char *tmp, char *ret, int fd)
{
	int i;

	i = 0;
	
	while (tmp[i] != '\0')
	{
		if (tmp[i] == ))
		{
			ft_strdup
		}
		i++;
	}
}

char	*get_next_line(int fd)
{
	char		*tmp;
	static char	*buffer = NULL;
	char		*ret;
	int			cap;
	int			len;

	if (tmp == NULL)
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	cap = read(fd, tmp, BUFFER_SIZE);
	if (cap < 0)
	{
		free (tmp);
		tmp = NULL;
		return (NULL);
	}
	if (cap == 0)
	{
		free (tmp);
		tmp = NULL;
		return (NULL);
	}
	tmp[cap] = '\0';
	return (ret);
}

int main(void)
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}