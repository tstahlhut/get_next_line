/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstahlhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:06:20 by tstahlhu          #+#    #+#             */
/*   Updated: 2023/04/03 16:56:17 by tstahlhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include	<stdlib.h>
# include	<unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif/*BUFFER_SIZE*/

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
int		ft_strlen_nl(const char *str);
int		check_line(char *str);
char	*read_and_stash(int fd, char *stash);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_copy_line(char *str, int i);
char	*ft_save_stash(char *str, int start);
void	free_str(char **str);
#endif/*GET_NEXT_LINE_BONUS_H*/
