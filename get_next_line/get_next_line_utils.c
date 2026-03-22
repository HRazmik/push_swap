/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:06:57 by marvin            #+#    #+#             */
/*   Updated: 2026/03/22 16:15:34 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list_gnl	*ft_lstlast(t_list_gnl *lst)
{
	t_list_gnl	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

char	*strlen_until_nl(t_list_gnl *lst)
{
	size_t	len;
	t_list_gnl	*tmp;
	char	*str;
	char	*s;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		s = tmp->str;
		while (*s && *s != '\n' && s++)
			len++;
		if (*s == '\n')
		{
			len++;
			break ;
		}
		tmp = tmp->next;
	}
	if (len == 0)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_get_line(t_list_gnl *lst)
{
	size_t	i;
	t_list_gnl	*tmp;
	char	*line;
	char	*dst;

	tmp = lst;
	line = strlen_until_nl(lst);
	if (!line)
		return (NULL);
	dst = line;
	while (tmp)
	{
		i = 0;
		while (tmp->str[i])
		{
			*dst++ = tmp->str[i];
			if (tmp->str[i++] == '\n')
				break ;
		}
		if (ft_strchr(tmp->str, '\n'))
			break ;
		tmp = tmp->next;
	}
	*dst = '\0';
	return (line);
}
