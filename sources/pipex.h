/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpassel <enpassel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:35:09 by enpassel          #+#    #+#             */
/*   Updated: 2025/01/02 16:43:34 by enpassel         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

/////Mandatory functions/////

int		main(int argc, char **argv, char **envp);
void	ft_child(char **argv, char **envp, int *fd);
void	ft_parent(char **argv, char **envp, int *fd);
void	execute(char *cmd, char **envp);
char	*find_path(char *cmd, char **envp);
void	ft_error(char *str, int status);
void	execute(char *args, char **envp);

#endif