/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_free_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:02:42 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/08 13:05:11 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

char	*ft_free(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (ptr);
}

void	ft_free_all_nodes(t_fdnode **list)
{
	t_fdnode	*actual;
	t_fdnode	*tmp;

	if (!list || !*list)
		return ;
	actual = *list;
	while (actual)
	{
		tmp = actual->next;
		free(actual->buffer);
		free(actual);
		actual = tmp;
	}
	*list = NULL;
}

char	*ft_freenode(t_fdnode **list, int fd)
{
	t_fdnode	*actual;
	t_fdnode	*previous;

	if (!list || !*list)
		return (NULL);
	actual = *list;
	previous = NULL;
	while (actual && actual->fd != fd)
	{
		previous = actual;
		actual = actual->next;
	}
	if (!actual)
		return (NULL);
	if (previous)
		previous->next = actual->next;
	else
		*list = actual->next;
	free(actual->buffer);
	actual->buffer = NULL;
	free(actual);
	actual = NULL;
	return (NULL);
}
