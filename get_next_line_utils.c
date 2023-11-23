/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:57:26 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/04/04 14:48:18 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"get_next_line.h"

/*free_str: frees given string and sets it to NULL */

void	free_str(char **str)
{
	if (*str && str)
	{
		free (*str);
		*str = NULL;
	}
}

/*ft_strlen: counts characters of given string until '\0' is hit
			and returns length of string 
			or 0 in case of empty string */

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == '\0')
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/*ft_strlen_nl: counts characters until a newline ("\n") is hit
				or the end of the string is reached
				returns length of string until newline */

int	ft_strlen_nl(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == '\0')
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

/*check_line: iterates through given string until a newline character ("\n") is found
				returns 1 if newline character was found
				returns 0 if not */

int	check_line(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*ft_strjoin: joins given strings (s1 and s2) and returns joined string */

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if ((s1 == NULL || *s1 == '\0') && (s2 == NULL || *s2 == '\0'))
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
	{
		free_str(&s1);
		return (NULL);
	}
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free_str(&s1);
	return (str);
}
