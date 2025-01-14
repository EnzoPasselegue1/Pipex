/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:14:26 by enpassel          #+#    #+#             */
/*   Updated: 2024/12/12 15:31:47 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_gnl(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	if (s[len] == '\n')
		len++;
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (dup);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1] = {0};
	char		*line;
	int			size;

	size = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_bzero_gnl(str), NULL);
	line = ft_strdup_gnl(str);
	if (!line)
		return (NULL);
	while (size && ft_check_return_gnl(line) == 0)
	{
		size = read(fd, str, BUFFER_SIZE);
		if (size == -1)
			return (ft_bzero_gnl(str), free(line), NULL);
		str[size] = '\0';
		line = ft_strjoin_gnl(line, str);
		if (line == NULL)
			return (NULL);
	}
	ft_clean_str_gnl(str);
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
