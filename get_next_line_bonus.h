/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:13:06 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 15:05:52 by azubieta         ###   ########.fr       */
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

# ifndef S_FDNODE
#  define S_FDNODE

typedef struct s_fdnode
{
	char			*buffer;
	int				fd;
	struct s_fdnode	*next;
}	t_fdnode;

# endif

/*get_next_line_bonus.c*/
char		*get_next_line(int fd);
char		*ft_free(char *ptr);

/*get_next_line_utils_bonus.c*/
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *str, int c);
t_fdnode	*ft_newnode(int fd);
char		*ft_freenode(t_fdnode **list, int fd);

#endif