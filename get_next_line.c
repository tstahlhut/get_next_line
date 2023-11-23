/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:00:53 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/04/04 14:58:38 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"get_next_line.h"

/*read_and_stash: reads from fd into buffer until a newline is hit
					stores everything in stash and returns stash
					or NULL in case of error of if fd has been read to its end
	r (return value of read) is set to 1
		as soon as r is 0, the end of the file is reached and the loop exited
		if r == -1 a read error occured and the buffer freed and NULL returned
	loops while check_line returns 0 (i.e. no newline ("\n") is found in stash)
	at the beginning of the loop the buffer the size of BUFFER_SIZE is allocated
	BUFFER_SIZE characters are read into the buffer
	buffer is terminated with '\0'
	stash and buffer are joined and stored in (new) stash
	buffer is freed
	when a newline character is found in stash, loop ends and stash is returned */

char	*read_and_stash(int fd, char *stash)
{
	int		r;
	char	*buf;

	r = 1;
	while (check_line(stash) == 0 && r > 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
		{
			free_str(&stash);
			return (NULL);
		}
		r = read(fd, buf, BUFFER_SIZE);
		if ((stash == NULL && r == 0) || r == -1)
		{
			free_str(&buf);
			return (NULL);
		}
		buf[r] = '\0';
		stash = ft_strjoin(stash, buf);
		free_str(&buf);
	}
	return (stash);
}

/*ft_save_stash: copies all characters after given start byte into destination string
			the given string is freed and the destination string returned
			in case of error or an empty string NULL is returned */

char	*ft_save_stash(char *str, int start)
{
	int		i;
	char	*dst;

	if (start == 0 || str[start] == '\0')
	{
		free_str(&str);
		return (NULL);
	}
	i = ft_strlen(str + start);
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
	{
		free_str(&str);
		return (NULL);
	}
	i = 0;
	while (str[start + i] != '\0')
	{
		dst[i] = str[start + i];
		i++;
	}
	dst[i] = '\0';
	free_str(&str);
	return (dst);
}

/*ft_copy_line: i bytes from str are copied into dst
				dst is returned
				in case of error NULL is returned*/

char	*ft_copy_line(char *str, int i)
{
	char	*dst;

	if (!str || str == NULL || *str == '\0')
		return (NULL);
	dst = malloc(sizeof(char) *(i + 1));
	if (!dst)
		return (NULL);
	dst[i] = '\0';
	while (i > 0)
	{
		i--;
		dst[i] = str[i];
	}
	return (dst);
}

/* get_next_line: reads from a file descriptor into a buffer and returns the first line (char *line)
					if called again, returns second line and so forth
					BUFFER_SIZE can be managed by compiling with -D BUFFER_SIZE=n
					user has to free line after use
	1. checks fd, BUFFER_SIZE and if file can be read
	2. reads from fd into buffer and stores in stash (adds buffer to previous stash if not NULL)
	3. calculates length of line (until "\n")
	4. stores line in *line
	5. saves rest of buf in stash
	6. returns line */

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			len;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		free_str(&stash);
		return (NULL);
	}
	stash = read_and_stash(fd, stash);
	len = ft_strlen_nl(stash);
	line = ft_copy_line(stash, len);
	if (line == NULL)
	{
		free_str(&stash);
		return (NULL);
	}
	stash = ft_save_stash(stash, len);
	return (line);
}
