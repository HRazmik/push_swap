/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:06:54 by rovnania          #+#    #+#             */
/*   Updated: 2026/03/22 16:08:38 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list_gnl	*ft_clean_list(t_list_gnl *lst)
{
	t_list_gnl	*current;
	t_list_gnl	*temp;
	char	*remaining_str;

	current = lst;
	while (current)
	{
		if (ft_strchr(current->str, '\n'))
		{
			remaining_str = ft_strdup(ft_strchr(current->str, '\n') + 1);
			free(current->str);
			if (!remaining_str)
				return (NULL);
			current->str = remaining_str;
			return (current);
		}
		else
		{
			temp = current;
			current = current->next;
			free(temp->str);
			free(temp);
		}
	}
	return (NULL);
}

int	add_to_list(t_list_gnl **lst, char *buffer)
{
	t_list_gnl	*new_node;
	t_list_gnl	*last_node;

	new_node = malloc(sizeof(t_list_gnl));
	if (!new_node)
	{
		free(buffer);
		return (0);
	}
	new_node->str = buffer;
	new_node->next = NULL;
	last_node = ft_lstlast(*lst);
	if (!*lst)
	{
		*lst = new_node;
		return (1);
	}
	last_node->next = new_node;
	return (1);
}

int	check_new_line(t_list_gnl *lst)
{
	t_list_gnl	*current;

	current = lst;
	while (current)
	{
		if (ft_strchr(current->str, '\n'))
			return (1);
		current = current->next;
	}
	return (0);
}

void	get_buffer(t_list_gnl **lst, int fd)
{
	int		read_bytes;
	int		flag;
	char	*buffer;

	buffer = NULL;
	flag = 1;
	while (!check_new_line(*lst) && flag)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buffer);
			if (read_bytes == -1)
				*lst = ft_clean_list(*lst);
			return ;
		}
		buffer[read_bytes] = '\0';
		flag = add_to_list(lst, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list_gnl	*lst;
	char			*buffer;

	buffer = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	get_buffer(&lst, fd);
	buffer = ft_get_line(lst);
	lst = ft_clean_list(lst);
	return (buffer);
}
