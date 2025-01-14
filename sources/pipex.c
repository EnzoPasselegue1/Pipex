/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:38:01 by enpassel          #+#    #+#             */
/*   Updated: 2025/01/14 12:19:19 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <bits/waitflags.h>
#include <stdio.h>
#include <sys/wait.h>

void	ft_child(char **argv, char **envp, int *fd)
{
	int	file;

	file = open(argv[1], O_RDONLY, 0777);
	if (file == -1)
		ft_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	close(fd[0]);
	close(file);
	close(fd[1]);
	execute(argv[2], envp);
}

void	ft_parent(char **argv, char **envp, int *fd)
{
	int	file;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		ft_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[1]);
	close(file);
	close(fd[0]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	pid = 0;
	if (argc != 5)
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_error();
	}
	else
	{
		if (pipe(fd) == -1)
			ft_error();
		pid = fork();
		if (pid == -1)
			ft_error();
		if (pid == 0)
			ft_child(argv, envp, fd);
		waitpid(pid, NULL, 0);
		ft_parent(argv, envp, fd);
	}
	return (0);
}
