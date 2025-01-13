/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:13:22 by enpassel          #+#    #+#             */
/*   Updated: 2025/01/13 17:05:17 by enpassel         ###   ########lyon.fr   */
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
	return (NULL);
}

void	ft_error(char *str, int status)
{
	//ft_putstr_fd("\033[31m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\033[0m\n", strlen(str));
    if(status != 0)
	    exit(status);
    else
        exit(EXIT_FAILURE);
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
		ft_error("Command not found", 127);
	}
    if (execve(path, cmd, envp) == -1)
	    ft_error("Command not found", 127);

}
