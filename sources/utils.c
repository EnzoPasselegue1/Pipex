/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:13:22 by enpassel          #+#    #+#             */
/*   Updated: 2025/01/14 12:24:43 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse(char *str)
{
	char	**cmd;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			cmd = ft_split(str, '\'');
			cmd[0] = ft_strtrim(cmd[0], " ");
			return (cmd);
		}
		else if (str[i] == '\"')
		{
			cmd = ft_split(str, '\"');
			cmd[0] = ft_strtrim(cmd[0], " ");
			return (cmd);
		}
		i++;
	}
	cmd = ft_split(str, ' ');
	return (cmd);
}

char	*find_path(char *cmd, char **envp)
{
	char	*command_path;
	char	*part_path;
	char	**path_list;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path_list = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_list[i])
	{
		part_path = ft_strjoin(path_list[i], "/");
		command_path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(command_path, F_OK) == 0)
			return (command_path);
		free(command_path);
		i++;
	}
	i = -1;
	while (path_list[++i])
		free(path_list[i]);
	free(path_list);
	return (0);
}

void	ft_error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	ft_error_message(void)
{
	ft_putstr_fd("\033[31mError: Command not found\n", 2);
	exit(126);
}

void	execute(char *args, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = -1;
	cmd = parse(args);
	path = find_path(cmd[0], envp);
	if (path == NULL)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		ft_error_message();
	}
	if (execve(path, cmd, envp) == -1)
		ft_error_message();
}
