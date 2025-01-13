/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:38:01 by enpassel          #+#    #+#             */
/*   Updated: 2025/01/13 16:47:45 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>
#include <stdio.h>
#include <bits/waitflags.h>

void	ft_child(char **argv, char **envp, int *fd)
{
	int	file;

	file = open(argv[1], O_RDONLY, 0777);
	if (file == -1)
		{
			ft_error("No such file or diectory", 1);
		}
	dup2(fd[1], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	close(fd[0]);
    close(file);
    close(fd[1]);
        int id = fork();
    if (id == 0)
        execute(argv[2], envp);
    else
        waitpid(id, NULL, WNOHANG);
}

void	ft_parent(char **argv, char **envp, int *fd)
{
	int	file;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		{
			ft_error("No such file or diectory", 1);
		}
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[1]);
    close(file);
    close(fd[0]);
    int id = fork();
    if (id == 0)
        execute(argv[3], envp);
    else
        waitpid(id, NULL, WNOHANG);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;
    pid = 0;

	if (argc != 5)
		ft_error("Usage: ./pipex file1 cmd1 cmd2 file2", 0);
	else
	{
		if (pipe(fd) == -1)
			ft_error("Pipe failed", 0);
		pid = fork();
		if (pid == -1)
			ft_error("Fork failed", 0);
		if (pid == 0)
			ft_child(argv, envp, fd);
        ft_parent(argv, envp, fd);
    }
	return (0);
}
