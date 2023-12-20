/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:00:38 by aaghla            #+#    #+#             */
/*   Updated: 2023/12/19 12:24:25 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != (char)c)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2, int rd)
{
	char	*str;
	int		i;

	if (!s1)
		s1 = "\0";
	i = ft_strlen(s1, 0);
	str = (char *)malloc((i + rd +1) * sizeof(char));
	if (!str)
	{
		if (s1[0])
			free(s1);
		return (NULL);
	}
	i = 0;
	rd = 0;
	while (s1[i])
		str[rd++] = s1[i++];
	i = 0;
	while (s2[i])
		str[rd++] = s2[i++];
	str[rd] = '\0';
	if (s1[0])
		free(s1);
	return (str);
}

// #include <libc.h>
// int main()
// {
// // 	int fd = open("fd1.txt", O_RDONLY);
// // 	char *s = NULL;
// // 	char p[BUFFER_SIZE + 1];
// // 	p[BUFFER_SIZE] = '\0';
// // 	int rd = read(fd, p, BUFFER_SIZE);
// // 	char *r = ft_strjoin(s, p);
// 	// printf("%s", r);

// 	// char *s1 = malloc(sizeof(char) * 1);
// 	// s1[0] = '\0';
// 	// char *s2="hello";
// 	// printf("%d", ft_strlen(s2));
// }