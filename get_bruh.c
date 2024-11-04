/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bruh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:50:18 by enoshahi          #+#    #+#             */
/*   Updated: 2024/11/04 12:40:10 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	get_the_difference(char *buffer, int cap)
// {
// 	int j;

// 	j = 0;
// }

char	*get_next_line(int fd)
{
	// * buffer: hold read elements, ret is what is returned, buf_len is the cap
	// * of how much to read, j is an indexer.
	// static variables by default start at NULL
	static char	*buffer = NULL;
	char		*ret;
	int			buf_len;
	int			cap;
	int			j;

	// if buf = NULL that means this is the functions first call, in which case we malloc
	if (buffer == NULL)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		buffer[0] = '\0';
	}
	// ?
	ret = NULL;
	// all of this runs WHILE strchr finds '\n', otherwise it returns NULL
	while (ft_strchr(ret, '\n') == NULL)
	{
		// if the buffer is null
		if (buffer[0] == '\0')
		{
			// read into the buffer
			buf_len = read(fd, buffer, BUFFER_SIZE);
			// if the amount read is a negative number (read failed) free and return NULL
			if (buf_len < 0)
			{
				free (buffer);
				if (ret != NULL)
					free (ret);
				buffer = NULL;
				return (NULL);
			}
			// if nothing was read it means the buffer is empty, so we free, set to NULL and return ret
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
			// get_the_difference(buffer, cap);
		}	
	return (ret);
}

// int main(void)
// {
// 	char *str;
// 	int fd;
// 	fd = open("text.txt", O_RDONLY);
// 	// ! IN THE CASE OF RETURNING POINTERS ALWAYSSS MAKE SURE TO FREE !!!!!!!
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// }
