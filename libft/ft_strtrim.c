/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovnania <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:13:59 by rovnania          #+#    #+#             */
/*   Updated: 2026/02/07 20:12:07 by rovnania         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (!set)
	{
		return (ft_strdup((char *)s1));
	}
	while (s1[start] && is_set(set, s1[start]))
		start++;
	while (end + 1 && is_set(set, s1[end]))
		end--;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}

// int main()
// {
// 	char *str1 = "1222223qweqr1111123";
// 	char *set = "123";
// 	printf("%s\n", ft_strtrim(str1, set));
// 	return 0;
// }