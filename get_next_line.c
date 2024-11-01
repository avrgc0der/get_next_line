/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:46:15 by enoshahi          #+#    #+#             */
/*   Updated: 2024/11/01 15:10:37 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*ret;
	int			buf_len;
	int			cap;
	int			j;

	if (buffer == NULL)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		buffer[0] = '\0';
	}
	ret = NULL;
	while (ft_strchr(ret, '\n') == NULL)
	{
		if (buffer[0] == '\0')
		{
			buf_len = read(fd, buffer, BUFFER_SIZE);
			if (buf_len < 0)
			{
				free (buffer);
				if (ret != NULL)
					free (ret);
				buffer = NULL;
				return (NULL);
			}
			if (buf_len == 0)
			{
				free (buffer);
				buffer = NULL;
				return (ret);
			}
			buffer[buf_len] = '\0';
		}
		cap = 0;
		j = 0;
		ret = ft_strjoin(ret, buffer);
		while (buffer[cap] != '\0')
		{
			if (buffer[cap] == '\n')
			{
				cap++;
				while (buffer[cap] != '\0')
				{
					buffer[j] = buffer[cap];
					cap++;
					j++;
				}
				buffer[j] = '\0';
				break;
			}
			cap++;
		}
		if (j == 0)
			buffer[0] = '\0';
	}	
	return (ret);
}

int main(void)
{
	char *str;
	int fd;
	fd = open("text.txt", O_RDONLY);
	// ! IN THE CASE OF RETURNING POINTERS ALWAYSSS MAKE SURE TO FREE !!!!!!!
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
}
