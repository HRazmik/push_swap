/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:06:44 by marvin            #+#    #+#             */
/*   Updated: 2026/03/22 16:09:16 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list_gnl
{
	char				*str;
	struct s_list_gnl	*next;
}	t_list_gnl;

char		*get_next_line(int fd);
void		get_buffer(t_list_gnl **lst, int fd);
int			check_new_line(t_list_gnl *lst);
int			add_to_list(t_list_gnl **lst, char *buffer);
char		*ft_get_line(t_list_gnl *lst);
t_list_gnl	*ft_clean_list(t_list_gnl *lst);
t_list_gnl	*ft_lstlast(t_list_gnl *lst);
char		*ft_strdup(char *src);
char		*ft_strchr(const char *s, int c);
#endif