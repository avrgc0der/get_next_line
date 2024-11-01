/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:46:15 by enoshahi          #+#    #+#             */
/*   Updated: 2024/10/30 18:47:15 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*tmp;
	static char	*buffer = NULL;
	char		*ret;
	int			cap;
	int			len;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	cap = read(fd, tmp, BUFFER_SIZE);
	if (cap < 0)
	{
		free (tmp);
		return (NULL);
	}
	if (cap == 0)
	{
		free (tmp);
		return (NULL);
	}
	tmp[cap] = '\0';
	
	// ! read up until \n
	while (ft_strchr(tmp, '\n') == NULL)
	{
		
	}
	if (!ft_strchr(tmp, '\n'))
	{
		// ! we keep reading until we find a new line
		
	}
	
	return (ret);
}

int main(void)
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}