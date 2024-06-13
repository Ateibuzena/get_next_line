/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:13:06 by azubieta          #+#    #+#             */
/*   Updated: 2024/05/14 21:45:45 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

# ifndef S_LIST
#  define S_LIST

typedef struct s_list
{
	char			*buffer;
	int				fd;
	struct s_list	*next;
}	t_list;

# endif

char	*get_next_line(int fd);
char	*ft_read_fd(int fd, char *buffer);
char	*ft_line(char *line);
char	*ft_free(char *ptr);
char	*ft_buffer_update(char *buffer);
t_list	*ft_newnode(int fd);
char	*ft_freenode(t_list **list, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);

#endif