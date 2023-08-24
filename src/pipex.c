/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:08:09 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/03 09:31:50 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	get_position(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	return (i);
}

static char	*get_path(char *cmd, char *envp[])
{
	int		i;
	char	**tem;
	char	*dir;
	char	*path;

	i = get_position(envp);
	if (envp[i] != NULL)
	{
		tem = ft_split((envp[i]) + 5, ':');
		dir = ft_strjoin("/", cmd);
		while (*tem)
		{
			path = ft_strjoin(*tem, dir);
			if (access(path, F_OK | X_OK) == 0)
			{
				free(dir);
				return (path);
			}
			free(path);
			tem++;
		}
	}
	return (cmd);
}

static void	exec(char *cmd, char *envp[])
{
	char	*path;
	char	**args;

	args = ft_split(cmd, ' ');
	path = get_path(args[0], envp);
	if (execve(path, args, envp) == -1)
	{
		perror("command not found");
		free(args);
		free(path);
		exit(1);
	}
	free(args);
	free(path);
}

void	child_pcs(int fd[], char *infile, char *cmd, char *envp[])
{
	int		infd;

	infd = open(infile, O_RDONLY);
	if (infd == -1)
	{
		perror("Open input file filed");
		exit(1);
	}
	dup2(infd, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	exec(cmd, envp);
}

void	parent_pcs(int fd[], char *outfile, char *cmd, char *envp[])
{
	int		outfd;

	outfd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfd == -1)
	{
		perror("Open output file filed");
		exit(1);
	}
	dup2(outfd, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	exec(cmd, envp);
}
