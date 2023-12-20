/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:59:22 by aaghla            #+#    #+#             */
/*   Updated: 2023/12/19 17:57:07 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_it(char *s)
{
	free(s);
	return (NULL);
}

char	*read_line(int fd, char *reached)
{
	char	*buff;
	int		rd;

	rd = 2;
	if (BUFFER_SIZE == 2147483647)
		rd = 1;
	buff = malloc((BUFFER_SIZE -1 + rd) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(reached, '\n') && rd > 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			if (reached)
				free(reached);
			return (free_it(buff));
		}
		if (rd == 0)
			break ;
		buff[rd] = '\0';
		reached = ft_strjoin(reached, buff, rd);
	}
	free(buff);
	return (reached);
}

char	*one_line(char *reached)
{
	char	*line;
	int		i;
	int		j;
	int		n;

	i = 0;
	j = -1;
	n = 1;
	if (!reached)
		return (NULL);
	while (reached[i] && reached[i] != '\n')
		i++;
	if (reached[i] == '\n')
		n = 2;
	line = malloc((i + n) * sizeof(char));
	if (!line)
		return (NULL);
	while (++j < i)
		line[j] = reached[j];
	if (n == 2)
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*next_line(char *reached)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!reached)
		return (NULL);
	else if (!reached[0] || !ft_strchr(reached, '\n'))
		return (free_it(reached));
	i = ft_strlen(reached, '\n');
	j = ft_strlen(reached, '\0');
	new = malloc((j + 1) * sizeof(char));
	if (!new)
		return (free_it(reached));
	j = 0;
	i = ft_strlen(reached, '\n') + 1;
	while (reached[i])
		new[j++] = reached[i++];
	new[j] = '\0';
	free(reached);
	if (!new[0])
		return (free_it(new));
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*reached;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reached = read_line(fd, reached);
	line = one_line(reached);
	reached = next_line(reached);
	return (line);
}
