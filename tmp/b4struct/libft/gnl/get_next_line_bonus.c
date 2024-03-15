/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:52:48 by oruban            #+#    #+#             */
/*   Updated: 2024/01/03 13:43:20 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Checks the statich remainder for '\n' and 
// if it is needed reads the file untill it gets '\n' or EOF ('\0')
// RETURNS 
// original remainder or remainder + what was read (line+remainder in 1 string)
static char	*get_read(int fd, char *remainder, char *buffer)
{
	ssize_t	readbytes;
	char	*tmp;

	readbytes = 1;
	if (!(remainder && ft_strchr(remainder, '\n')))
	{
		while (readbytes > 0)
		{
			readbytes = read(fd, buffer, BUFFER_SIZE);
			if (readbytes == -1)
				return (NULL);
			else if (readbytes == 0)
				break ;
			buffer[readbytes] = '\0';
			if (!remainder)
				remainder = ft_strdup("");
			tmp = remainder;
			remainder = ft_strjoin(remainder, buffer);
			free(tmp);
			tmp = NULL;
			if (ft_strchr(buffer, '\n'))
				break ;
		}
	}
	return (remainder);
}

// assings static variable the line from '\n' till '\0' of original line/a
// sets after 1st '\n' of variable line/a '\0'
static char	*form_line_remainder(char *line)
{
	char	*str;
	ssize_t	i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	str = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*str == 0)
	{
		free(str);
		str = NULL;
	}
	line[i + 1] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	static char	*remainder [OPEN_MAX];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	line = get_read(fd, remainder[fd], buffer);
	if (!line)
		return (NULL);
	remainder[fd] = form_line_remainder(line);
	return (line);
}

// // #include "get_next_line.h"
// #include "get_next_line_bonus.h"
// #include <fcntl.h>

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;

// 	fd1 = open("test.txt", O_RDONLY);
// 	// fd1 = open("test1.txt", O_RDONLY);
// 	// fd1 = open("only_nl.txt", O_RDONLY);
// 	// fd1 = open("1char.txt", O_RDONLY);
// 	// fd1 = open("one_line_no_nl.txt", O_RDONLY);
// 	// fd1 = open("empty.txt", O_RDONLY);
// 	fd2 = open("lines_around_10.txt", O_RDONLY);
// 	fd3 = open("read_error.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: '%s'\n", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s\n", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s\n", i, line);
// 		free(line);
// 		i++;
// 	}
// 	// printf("\nThe programm is running OPEN_MAX = %i\n", OPEN_MAX);
// 	// sleep(100);
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }
