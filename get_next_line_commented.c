/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_commented.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi <enoshahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:46:15 by enoshahi          #+#    #+#             */
/*   Updated: 2024/11/01 15:00:06 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	// static variables always start at an initial value, by default start at NULL.
	static char	*buffer = NULL;
	char		*ret;
	int			cap;
	int			len;

// THIS IS ALL JUST MALLOC'ING AND READING THE BUFFER:
	// if buffer is NULL that means its the first time its being called, it will never be the same condition again
	if (buffer == NULL)
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// read returns the no. of bytes read and if it returns less than 0 then its an impossible value
	// and we must return an empty string, cap just stores no of chars read/to read.
	cap = read(fd, buffer, BUFFER_SIZE);
	// we only free if the file is corrupt OR if its reached the end!!!
	if (cap < 0)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	if (cap == 0)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer[cap] = '\0';
	// "Hello\n this is me.\n"
	// I want to read the buffer and then find the new line occurance and then return up until it, while storing the stuff that comes after it in the static buffer
	// we null term the end of the content.
	
	while ()
	
	return (buffer);
}

int main(void)
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}

// i wanna read and check for '/n', 
//if seen then i will dup it into the static buffer and return it
// a file is just one big string, technically
// read(int fd, void *buf, size_t n)
// fd 0, 1, 2, "3" tmp.file

// ? ||===========================|| 
// ! ||       BUFFER_SIZE=9       ||
// * ||  .txt = "Hello\nWorld\n"  ||
// * ||  *buf = "Wor"	  ||
// * ||  *ret = "HelloWor"         ||
// * ||  remain: ""               ||
//   || before \n: RETURN         ||
//   || after \n: STATIC BUFFER   ||
//   || read data: TEMP           ||
// ? ||===========================||

int i;
int j;
i = 0;
i = 5;
j = 0;
while (str[i] != '\0')
{
	str[j] = str[i];
	i++;
	j++;
	str[j] = '\0';
}
Hello\n

char a[]


// when gnl runs, it will:
// 1. read from the .txt up until the BUF_SIZE       |
// 2. then it will store what it read in *tmp        |
// 3. read up until '\n', store what comes after     
// in the static *buf
// 4. nul term the last char in the *tmp index and
// store it in *ret, return that

// 3. read *tmp up until the \n and then dup it to ret.

// ! Hello World\n*