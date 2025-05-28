/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:13:06 by azubieta          #+#    #+#             */
/*   Updated: 2024/05/15 18:36:42 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

/*get_next_line.c*/
char	*get_next_line(int fd);

/*get_next_line_utils.c*/
char	*ft_strjoin_getnextline(char *s1, char *s2);
char	*ft_strchr_getnextline(const char *s, int c);
size_t	ft_strlen_getnextline(const char *s);
char	*ft_free(char *ptr);

#endif